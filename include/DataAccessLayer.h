/******************************************************************************
 *
 *	DataAccessLayer.h
 *
 *	Encpasulates the connection to the DB and provides all the overall
 *      operations/transactions needed by the application. It's a single
 *      data access entity.
 *
 *	Created at:
 *	2012-01-16
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef _DATAACCESSLAYER_H
#define _DATAACCESSLAYER_H

#include <iostream>
#include <string>
#include <list>
#include <exception>
#include <utility>

#include <occi.h>

#include <boost/graph/adjacency_list.hpp>

#include "includes.h"
#include "PriorityQueue.h"

namespace core
{

class DataAccessException : public std::exception
{
private:
    std::string message;
    std::string sqlError;

public:
    DataAccessException(const std::string &msg,
                        const std::string &error) : std::exception(), message(msg), sqlError(error) {}

    const char* what() { return message.c_str(); }

    const std::string& getSqlError() { return sqlError; }


};

class DataAccessLayer
{
private:
    static const std::string DEF_USER = "B5-8";
    static const std::string DEF_PASS = "cjrrs";
    static const std::string DEF_CONN = "gandalf.isep.ipp.pt:1521/isepdb";

    static DataAccessLayer *instance;
    oracle::occi::Environment *environment;
    oracle::occi::Connection *connection;

    core::PriorityQueue requests;

    void connect(const std::string &user = DEF_USER,
                const std::string &pass = DEF_PASS,
                const std::string &conn = DEF_CONN);

public:


    static DataAccessLayer* getInstance();

    ~DataAccessLayer();

    /**
     * Returns an instance of a Colaborador if it is found. If not,
     * throws an exception.
     *
     * @param id the ID of the colaborador to search
     * @returns an instance of the colaborador saught after
     * @throws a DataAccessException if the colaborador can't be
     * found
     */
    dmd::Colaborador getColaborador(dmd::ColaboradorId id);

    dmd::Categoria getCategoria(int idCategoria);

    dmd::Progressao getProgressao(int idProg);

    /**
     * Returns a list of Operacao allowed for a given Colaborador.
     *
     * @param id the ID of the colaborador
     * @returns a list of Operacao (could be empty, if he has no
     * accesses)
     * @throws a DataAccessException if the colaborador can't be found
     */
    std::list<dmd::Operacao> getAllowedOperacoes(dmd::ColaboradorId id);

    /**
     * Obtains all Beneficio currently active.
     *
     * @returns a list of active Beneficio
     */
    std::list<dmd::Beneficio> getBeneficios();

    /**
     * Obtains the PlanoBeneficios for a given Colaborador.
     *
     * @param id the ID of the Colaborador
     * @returns the PlanoBeneficios for a Colaborador
     * @throws a DataAccessException if the colaborador can't be found
     */
    dmd::PlanoBeneficio getBeneficios(dmd::ColaboradorId id);

    /**
     * Submits a PropostaProgressao to the system, for avaliation
     * by the competent entities.
     *
     * @param proposta the PropostaProgressao to submit
     * @throws a DataAccessException if it doesn't meet the progression
     * criteria
     */
    void submitPropostaProgressao(const dmd::PropostaProgressao &proposta);

    /**
     * Submits a PlanoBeneficios to the system, for avaliation
     * by the competent entities.
     *
     * @param plano the PlanoBeneficios to submit
     * @throws a DataAccessException if it's rejected by the system
     */
    void submitPropostaPlanoBeneficios(const dmd::PlanoBeneficio &plano);

    /**
     * Obtains a list of Categoria for a given Colaborador.
     *
     * @param id the of the Colaborador
     * @returns a list of Categoria
     * @throws a DataAccessException if the colaborador can't be found
     */
    std::list<dmd::Categoria> getCategorias(dmd::ColaboradorId id);

    /**
     * Submits DadosPessoais proposal to the system, for evaluation
     * by the competent entities.
     *
     * @param plano the DadosPessoais to submit
     */
    void submitPropostaDadosPessoais(const dmd::PropostaDadosPessoais &proposta);

    /**
     * Get the career (graph form) for a Colaborador (you
     * gain ownership of the object).
     *
     * @param id the ID of the Colaborador
     * @returns the graph representing the career he has taken
     */
    dmd::PlanoCarreira* getCareer(dmd::ColaboradorId id);

    /**
     * Allows an authority entity to approve a Progressao.
     *
     * @param progressao the progressao to approve
     * @throws DataAccessException if the progressao isn't found
     */
    void approveProgressao(const dmd::Progressao &progressao);

    /**
     * Imports an employee CSV data file into the DB.
     *
     * @param pathToFile the path to the CSV file
     * @throws DataAccessException if the file can't be
     * open/found or the user has no permissions to read
     */
    void importCSV(const std::string &pathToFile);

    /**
     * Exports all employee data into a CSV data file.
     *
     * @param pathToFile the path to destiny file
     * @throws DataAccessException
     */
    void exportCSV(const std::string &pathToFile);
};

}

#endif /* _DATAACCESSLAYER_H */
