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
using dmd::ColaboradorId
using dmd::Operacao;
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

list<Operacao> getAllowedOperacoes(ColaboradorId id)
{
    list<Operacao> ret;

    // first we get the allowed operations by group
    string byGroup = "SELECT op.DESCRICAO FROM OPERACAO op, ACESSO ac, GRUPO g " \
        "WHERE g.ID_COLABORADOR = :idColab AND ac.ID_GRUPO = g.ID_GRUPO AND ac.ID_OP = op.ID_OP";

    Statement *statement = connection->createStatement(byGroup);

    statement->setNumber(1, Number(id));
    ResultSet *res = statement->executeQuery();

    while (res->next())
    {
        try
        {
            ret.push_back(res->getNumber(1));
        }
        catch (SQLException ex)
        {
            statement->closeResultSet(res);
            connection->terminateStatement(statement);

            throw DataAccessException(ex.getMessage(), ex.getErrorCode());
        }
    }
}
