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
using boost::gregorian::date;

using namespace dmd;

using core::DataAccessLayer;
using core::DataAccessException;
using core::PriorityQueue;
using core::Priority;
using core::CRITERIAS;

DataAccessLayer* DataAccessLayer::getInstance()
{
    if (!DataAccessLayer::instance)
    {
        DataAccessLayer::instance = new DataAccessLayer();
        DataAccessLayer::instance->connect();

        list<PropostaProgressao> progs = getPropostasProgressao();

        /*for (list<PropostaProgressao>::iterator itr = progs.begin(); itr != progs.end(); itr++)
        {
            PropostaProgressao &proposta = *itr;
            Colaborador col = getColaborador(proposta.first);

            Priority p;
            p.first[0] = CRITERIAS::CATEGORY;
            p.first[1] = CRITERIAS::AGE;

            p.second =
        }*/
    }

    return DataAccessLayer::instance;
}

DataAccessLayer::~DataAccessLayer()
{
    environment->terminateConnection(connection);
    Environment::terminateEnvironment(environment);

    delete planoCarreira;
}

Colaborador DataAccessLayer::getColaborador(ColaboradorId id)
{
    string query = "SELECT ID_COLABORADOR, NOME, MORADA, CONTACTO, NIF, EMAIL, PASSWORD, SALARIO, ID_CATEGORIA FROM COLABORADOR WHERE ID_COLABORADOR = :idColab";

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
        colab.setCategoria(res->getNumber(9));
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
            ret.setBudget(res->getNumber(1));
            ret.addBeneficio(Beneficio(res->getString(2), res->getNumber(3), res->getString(4) == "Y", res->getNumber(5)));
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

Categoria DataAccessLayer::getCategoria(int idCategoria)
{
    string query = "SELECT cat.NOME_CATEGORIA, cat.SALARIO_BASE, cat.DESIGNACAO, cat.MAX_COLABORADORES, a.DESCRICAO, pl.ID_PLANO_CARREIRA, ben.ID_PLANO_BENEFICIO FROM CATEGORIA cat, AREA a, PLANO_CARREIRA pl, PLANO_BENEFICIOS ben WHERE cat.ID_CATEGORIA = :idCat AND pl.ID_PLANO_CARREIRA = cat.ID_PLANO_CARREIRA AND a.ID_AREA = cat.ID_AREA AND ben.ID_PLANO_BENEFICIO = cat.ID_PLANO_BENEFICIO";

    Statement *statement = connection->createStatement(query);
    statement->setNumber(1, Number(idCategoria));
    ResultSet *res = statement->executeQuery();
    res->next();

    Categoria cat;

    cat.setName(res->getString(1));
    cat.setBaseSalary(res->getNumber(2));
    cat.setDescription(res->getString(3));
    cat.setMaxEmployees(res->getNumber(4));
    cat.setArea(res->getString(5));
    cat.setPlanoCarreira(res->getNumber(6));
    cat.setPlanoBeneficio(res->getNumber(7));

    statement->closeResultSet(res);
    connection->terminateStatement(statement);

    return cat;
}

MyDate toDate(oracle::occi::Date oracleDate)
{
    int y = 0;
    unsigned int m = 0, d = 0, H = 0, M = 0, S = 0;

    oracleDate.getDate(y, m, d, H, M, S);

    return date(y, m, d);
}

list<PropostaProgressao> getPropostasProgressao(ColaboradorId id = -1)
{
    string query = "SELECT ID_PROG, ID_COLABORADOR FROM PROPOSTA_PROGRESSAO" + (id > 0) ? "WHERE ID_COLABORADOR = :idColab" : "";

    Statement *statement = connection->createStatement(query);

    if (id > 0)
        statement->setNumber(1, Number(id));

    ResultSet *res = statement->executeQuery();

    list<PropostaProgressao> l;
    PropostaProgressao p;

    while (res->next())
    {
        p.first = res->getNumber(1);
        p.second = res->getNumber(2);
        l.push_back(p);
    }

    return l;
}

Progressao getProgressao(int idProg)
{
    string query = "SELECT prog.DATA_PROG, prog.SALARIO_ANTERIOR, prog.SALARIO_NOVO, colab.ID_COLABORADOR, cat.ID_CATEGORIA FROM PROGRESSAO prog, CATEGORIA cat, COlABORADOR colab WHERE prog.ID_PROG = :idP AND cat.ID_CATEGORIA = prog.ID_CATEGORIA AND colab.ID_COlABORADOR = prog.ID_COLABORADOR";

    Statement *statement = connection->createStatement(query);
    statement->setNumber(1, Number(idProg));
    ResultSet *res = statement->executeQuery();
    res->next();

    Progressao p;

    p.setDataProgressao(toDate(res->getDate(1)));
    p.setSalarioAnterior(res->getNumber(2));
    p.setSalarioNovo(res->getNumber(3));
    p.setColaborador(getColaborador(res->getNumber(4)));
    p.setCategoria(getCategoria(res->getNumber(5)));

    statement->closeResultSet(res);
    connection->terminateStatement(statement);

    return p;
}

/*
PlanoCarreira* DataAccessLayer::getCareer(ColaboradorId id)
{
    PlanoCarreira *planoCarreira = new PlanoCarreira();
    CareerGraph *graph = planoCarreira->getCareerGraph();


    string query = "SELECT prog.ID_PROG, cat.ID_CATEGORIA, pl.DESC, pl.ID_PLANO_CARREIRA FROM PROGRESSAO prog, CATEGORIA cat, COLABORADOR col, PLANO_CARREIRA pl WHERE col.ID_COLABORADOR = :idColab AND prog.ID_COLABORADOR = :idColab AND cat.ID_CATEGORIA = prog.ID_CATEGORIA AND pl.ID_PLANO_CARREIRA = cat.ID_PLANO_CARREIRA ORDER BY prog.DATA_PROG DESC";

    Statement *statement = connection->createStatement(query);
    statement->setNumber(1, Number(id));
    ResultSet *res = statement->executeQuery();

    res->next();

    Progressao firstProg = getProgressao(res->getNumber(1));

    res->next();

    Progressao secondProg = getProgressao(res->getNumber(1));

    add_edge(firstProg, secondProg, graph);

    firstProg = secondProg;
    while (res->next())
    {
        secondProg = getProgressao(res->getNumber(1));

        if (secondProg.getCategoria().getPlanoCarreira() != firstProg.getCategoria().getPlanoCarreira())
        {
        }
    }


    return planoCarreira;
}
*/


