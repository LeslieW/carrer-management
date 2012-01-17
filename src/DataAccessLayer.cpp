#include "DataAccessLayer.h"

#include <iostream>
#include <string>
#include <list>

#include <occi.h>

#include <boost/graph/adjacency_list.hpp>

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

    Colaborador colab;

    try
    {
        colab.setId(res->getNumber(1)());
        colab.setName(res->getString(2));
        colab.setAdress(res->getString(3));
        colab.setPhone(res->getNumber(4)());
        colab.setNIF(res->getNumber(5)());
        colab.setEmail(res->getString(6));
        colab.setPassword(res->getString(7));
        colab.setSalario(res->getNumber(8)());
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

