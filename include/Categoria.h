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

typedef unsigned double Salary;

class Categoria
{
private:
    std::string description;
    std::string name;

    Salary baseSalary;

    unsigned int maxEmployees;

    std::string area;
    int idPlanoCarreira;
    int idPlanoBeneficios;

public:
    Categoria();

    // GETTERS
    const std::string& getDescription() const { return description; }
    const std::string& getName() const { return name; }
    Salary getBaseSalary() const { return baseSalary; }
    unsigned int getMaxEmployees() const { return maxEmployees; }
    const std::string& getArea() const { return area; }
    int getPlanoBeneficio() const { return planoBeneficio; }
    int getPlanoCarreira() const { return planoCarreira; }

    // SETTERS
    void setDescription(const std::string &desc) { description = desc; }
    void setName(const std::string &_name) { name = _name; }
    void setBaseSalary(Salary salary) { baseSalary = salary; }
    void setMaxEmployees(unsigned int max) { maxEmployees = max; }
    void setArea(const std::string &_area) { area = _area; }
    void setPlanoBeneficio(int plano) { planoBeneficio = plano; }
    void setPlanoCarreira(int plano) { planoCarreira = plano; }

};

}

#endif /* _CATEGORIA_H */
