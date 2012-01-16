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

#include <occi.h>

#include "Colaborador.h"

namespace core
{

class DataAccessLayer
{
private:
    static const std::string DEF_USER = "B5-8";
    static const std::string DEF_PASS = "cjrrs";
    static const std::string DEF_CONN = "gandalf.isep.ipp.pt:1521/isepdb";

    DataAccessLayer *instance;
    oracle::occi::Environment *environment;
    oracle::occi::Connection *connection;

public:
    static const DataAccessLayer* getInstance();

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

    /**
     * Returns a list of Operacao allowed for a given Colaborador.
     *
     * @param id the ID of the colaborador
     * @returns a list of Operacao (could be empty, if he has no
     * accesses)
     * @throws a DataAccessException if the colaborador can't be found
     */
    std::list<dmd::Operacao> getAllowedOperacoes(dmd::ColaboradorId id);
};

}

#endif /* _DATAACCESSLAYER_H */
