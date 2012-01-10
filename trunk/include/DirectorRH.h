/******************************************************************************
 *
 *	DirectorRH.h
 *
 *	Main header for DirectorRH class
 *
 *	Created at:
 *	2012-01-10
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef DRH_H
#define DRH_H

#include <iostream>
#include <string>
using namespace std;

using namespace col;
#include "Colaborador.h"
#include "DirectorRH.h"

class DirectorRH: public RH {
private:

public:
	/**   Constructor section */
	/* default Constructor of the employee */
			DirectorRH();
	 /* full  Constructor of the employee */
			DirectorRH(const string& name, const string& adress, const string& email,const string& password, int nif, int phone, double salary);
	 /* copy  Constructor of the employee */
			DirectorRH(const DirectorRH&);
	 /* delete employee */
			~DirectorRH();
 */
	/*	 *   end Constructor section	 */
};

#endif
