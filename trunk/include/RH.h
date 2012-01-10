/******************************************************************************
 *
 *	RH.h
 *
 *	Main header for RH class
 *
 *	Created at:
 *	2012-01-10
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef RH_H_
#define RH_H_

#include <iostream>
#include <string>
using namespace std;

using namespace col;
#include "Colaborador.h"

class RH: public Colaborador {
private:

public:
	/**   Constructor section */
	/* default Constructor of the employee */
					RH();
	 /* full  Constructor of the employee */
					RH(const string& name, const string& adress, const string& email,const string& password, int nif, int phone, double salary);
	 /* copy  Constructor of the employee */
					RH(const RH&);
	 /* delete employee */
					~Colaborador();
 */
	/*	 *   end Constructor section	 */
};

#endif
