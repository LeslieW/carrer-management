/******************************************************************************
 *
 *	Categoria.h
 *
 *	Main header for Categoria class
 *	This class is responsable for store the information about funcionalitys for application
 *
 *	Created at:
 *	2012-01-10
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef _CATEGORIA_H_
#define _CATEGORIA_H_

#include <iostream>
#include <string>

#include "Area.h"
#include "PlanoBeneficio.h"
#include "PlanoCarreira.h"

namespace dmd
{

class Categoria
{
private:
    std::string description;
    std::string name;

    Salary baseSalary;

    unsigned int maxEmployees;

    dmd::Area area;
    dmd::PlanoBeneficio planoBeneficio;
    dmd::PlanoCarreira planoCarreira;

public:
    typedef unsigned double Salary;

    Categoria();

    // GETTERS
    const std::string& getDescription() const { return description; }
    const std::string& getName() const { return name; }
    Salary getBaseSalary() const { return baseSalary; }
    unsigned int getMaxEmployees() const { return maxEmployees; }
    const dmd::Area& getArea() const { return area; }
    const dmd::PlanoBeneficio& getPlanoBeneficio() const { return planoBeneficio; }
    const dmd::PlanoCarreira& getPlanoCarreira() const { return planoCarreira; }

    // SETTERS
    void setDescription(const std::string &desc) { description = desc; }
    void setName(const std::string &_name) { name = _name; }
    void setBaseSalary(Salary salary) { baseSalary = salary; }
    void setMaxEmployees(unsigned int max) { maxEmployees = max; }
    void setArea(const dmd::Area &_area) { area = _area; }
    void setPlanoBeneficio(const dmd::PlanoBeneficio &plano) { planoBeneficio = plano; }
    void setPlanoCarreira(const dmd::PlanoCarreira &plano) { planoCarreira = plano; }

};

}

#endif /* _CATEGORIA_H */
