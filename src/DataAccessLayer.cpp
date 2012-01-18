#include "DataAccessLayer.h"

#include <iostream>
#include <string>
#include <list>

#include <occi.h>

#include <boost/graph/adjacency_list.hpp>

#include "includes.h"

using std::string;
using std::list;

using oracle::occi::Environment;
using oracle::occi::Connection;
using oracle::occi::Statement;
using oracle::occi::ResultSet;
using oracle::occi::Number;
using oracle::occi::SQLException;

using boost::adjacency_list;

using dmd::Colaborador;
using dmd::ColaboradorId;
using dmd::Operacao;
using dmd::Beneficio;
using dmd::PlanoBeneficio;
using core::DataAccessLayer;
using core::DataAccessException;

DataAccessLayer* DataAccessLayer::getInstance()
{
    if (!DataAccessLayer::instance)
    {
        DataAccessLayer::instance = new DataAccessLayer();
        DataAccessLayer::instance->connect();
    }

    return DataAccessLayer::instance;
}

DataAccessLayer::~DataAccessLayer()
{
    environment->terminateConnection(connection);
    Environment::terminateEnvironment(environment);
}

Colaborador DataAccessLayer::getColaborador(ColaboradorId id)
{
    string query = "SELECT ID_COLABORADOR, NOME, MORADA, CONTACTO, NIF, EMAIL, PASSWORD, SALARIO FROM COLABORADOR WHERE ID_COLABORADOR = :idColab";

    Statement *statement = connection->createStatement(query);

    statement->setNumber(1, Number(id));
    ResultSet *res = statement->executeQuery();
    res->next();

    Colaborador colab;

    try
    {
        colab.setId(res->getNumber(1));
        colab.setName(res->getString(2));
        colab.setAdress(res->getString(3));
        colab.setPhone(res->getNumber(4));
        colab.setNIF(res->getNumber(5));
        colab.setEmail(res->getString(6));
        colab.setPassword(res->getString(7));
        colab.setSalario(res->getNumber(8));
    }
    catch (SQLException ex)
    {
        // house keeping
        statement->closeResultSet(res);
        connection->terminateStatement(statement);

        throw DataAccessException(ex.getMessage(), ex.getErrorCode());
    }

    // house keeping-
    statement->closeResultSet(res);
    connection->terminateStatement(statement);

    return colab;


}

list<Operacao> DataAccessLayer::getAllowedOperacoes(ColaboradorId id)
{
    list<Operacao> ret;

    string byGroup = "SELECT op.DESCRICAO FROM OPERACAO op, ACESSO ac, GRUPO g " \
        "WHERE (g.ID_COLABORADOR = :idColab AND ac.ID_GRUPO = g.ID_GRUPO AND ac.ID_OP = op.ID_OP) OR (ac.ID_COLABORADOR = :idColab AND op.ID_OP = ac.ID_OP)";

    Statement *statement = connection->createStatement(byGroup);

    statement->setNumber(1, Number(id));
    ResultSet *res = statement->executeQuery();

    while (res->next())
    {
        try
        {
            ret.push_back(Operacao(res->getString(1)));
        }
        catch (SQLException ex)
        {
            statement->closeResultSet(res);
            connection->terminateStatement(statement);

            throw DataAccessException(ex.getMessage(), ex.getErrorCode());
        }
    }

    statement->closeResultSet(res);
    connection->terminateStatement(statement);

    return ret;
}

list<Beneficio> DataAccessLayer::getBeneficios()
{
    list<Beneficio> ret;

    string query = "SELECT NOME, TEMPO_FIDELIZACAO, REGIME, CUSTO FROM BENEFICIO";

    Statement *statement = connection->createStatement(query);
    ResultSet *res = statement->executeQuery();

    while (res->next())
    {
        try
        {
            ret.push_back(Beneficio(res->getString(1), res->getNumber(2), res->getString(3) == "Y",
                                    res->getNumber(4)));
        }
        catch (SQLException ex)
        {
            statement->closeResultSet(res);
            connection->terminateStatement(statement);

            throw DataAccessException(ex.getMessage(), ex.getErrorCode());
        }
    }

    statement->closeResultSet(res);
    connection->terminateStatement(statement);

    return ret;
}

PlanoBeneficio DataAccessLayer::getBeneficios(ColaboradorId id)
{
    PlanoBeneficio ret;

    string query = "SELECT pl.ORCAMENTO, be.NOME, be.TEMPO_FIDELIZACAO, be.REGIME, be.CUSTO " \
            "FROM PLANO_BENEFICIOS pl, REGISTO_BENEFICIO re, BENEFICIO be " \
            "WHERE re.ID_COLABORADOR = :idColab AND re.ID_PLANO_BENEFICIO = pl.ID_PLANO_BENEFICIO AND be.ID_PLANO_BENEFICIO = pl.ID_PLANO_BENEFICIO";

    Statement *statement = connection->createStatement(query);

    statement->setNumber(1, Number(id));
    ResultSet *res = statement->executeQuery();

    while (res->next())
    {
        try
        {
            ret.addBeneficio(Beneficio(res->getString(2), res->getNumber(3),
                                       res->getString(4) == "Y", res->getNumber(5)));
        }
        catch (SQLException ex)
        {
            statement->closeResultSet(res);
            connection->terminateStatement(statement);

            throw DataAccessException(ex.getMessage(), ex.getErrorCode());
        }
    }

    ret.setBudget(res->getNumber(1));

    statement->closeResultSet(res);
    connection->terminateStatement(statement);

    return ret;
}
