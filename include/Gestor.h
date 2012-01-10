/******************************************************************************
 *
 *	Gestor.h
 *
 *	Main header for Gestor class
 *
 *	Created at:
 *	2012-01-10
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef GESTOR_H_
#define GESTOR_H_

#include <iostream>
#include <string>
using namespace std;
using namespace col;
#include "Colaborador.h"

class Gestor: public Colaborador {
private:

public:
	/**   Constructor section */
	/* default Constructor of the employee */
					Gestor();
	 /* full  Constructor of the employee */
					Gestor(const string& name, const string& adress, const string& email,const string& password, int nif, int phone, double salary);
	 /* copy  Constructor of the employee */
					Gestor(const Gestor&);
	 /* delete employee */
					~Gestor();

	/*	 *   end Constructor section	 */
};

#endif
