/******************************************************************************
 *
 *	Beneficio.h
 *
 *	Encpasulates a Beneficio
 *
 *	Created at:
 *	2012-01-17
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef _BENEFICIO_H
#define _BENEFICIO_H

#include <iostream>
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>

#include "Categoria.h"

namespace dmd
{

typedef boost::gregorian::date MyDate;

class Beneficio
{
private:
    std::string name;
    unsigned int tempoFidelizacao;
    bool isParcial;
    dmd::Salary cost;

    Beneficio();

    Beneficio(const std::string &_name, unsigned int _tempoFidelizacao,
              bool _isParcial = false, dmd::Salary _cost) :
        name(_name), tempoFidelizacao(_tempoFidelizacao), isParcial(_isParcial), cost(_cost) {}

    const std::string& getName() const { return name; }
    unsigned int getTempoFidelizacao() const { return tempoFidelizacao; }
    bool isParcial() const { return isParcial; }

    void setName(const std::string &_name) { name = _name; }
    void setTempoFidelizacao(unsigned int _tempoFidelizacao) { tempoFidelizacao = _tempoFidelizacao; }
    void isParcial(bool b) { isParcial = b; }
    void setCost(dmd::Salary _cost) { cost = _cost; }
};

}

#endif /* _BENEFICIO_H */
