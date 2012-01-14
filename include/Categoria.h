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

#ifndef Categoria_H_
#define Categoria_H_

#include <iostream>
#include <string>
using namespace std;

using namespace col;

class Categoria {
private:
	/* description of Category */
	string 	description,
			name;
	double	baseSalary;

	int 	maxEmployee;

	Area*	area;
	PlanoBeneficio*	planoBeneficio;
	PlanoCarreira*	planoCarreira;

public:
	/**   Constructor section */
	/* default funcionalaty */
			Categoria();
	 /* full  funcionalaty  */
			Categoria(const description& name);
	 /* copy  Constructor of the employee */
			Categoria(const Categoria&);
	 /* delete employee */
			~Categoria();
 */
	/*	 *   end Constructor section	 */
};

#endif
