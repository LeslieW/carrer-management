/******************************************************************************
 *
 *	PlanoBeneficio.h
 *
 *	Encapsulates a list of Beneficio.
 *
 *	Created at:
 *	2012-01-17
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef _PLANOBENEFICIO_H
#define _PLANOBENEFICIO_H

#include <iostream>
#include <string>
#include <list>

#include "Beneficio.h"

namespace dmd
{

class PlanoBenficio
{
private:
    std::list<dmd::Beneficio> beneficios;
    unsigned double budget;

    PlanoBeneficio(unsigned double _budget = 0.0f) :
            budget(_budget) {}

    const std::list<dmd::Beneficio>& getBeneficios() const { return beneficios; }
    unsigned double getBudget() const { return budget; }

    void setBudget(unsigned double b) { budget = b; }
    void setBeneficios(const std::list<dmd::Beneficio> &_beneficios) { beneficios = _beneficios; }

    void addBeneficio(const dmd::Beneficio &beneficio) { beneficios.push_back(beneficio); }
};

}

#endif /* _PLANOBENEFICIO_H */
