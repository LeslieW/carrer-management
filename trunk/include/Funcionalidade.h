/******************************************************************************
 *
 *	Funcionalidade.h
 *
 *	Main header for Funcionalidade class
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

#ifndef FUNC_H_
#define FUNC_H_

#include <iostream>
#include <string>
using namespace std;

using namespace col;

class Funcionalidade {
private:
	/* description of funcionalaty */
	string description;
	int key;

public:
	/**   Constructor section */
	/* default funcionalaty */
			Funcionalidade();
	 /* full  funcionalaty  */
			Funcionalidade(const description& name);
	 /* copy  Constructor of the employee */
			Funcionalidade(const Funcionalidade&);
	 /* delete employee */
			~Funcionalidade();
 */
	/*	 *   end Constructor section	 */
};

#endif
