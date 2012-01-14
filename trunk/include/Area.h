/******************************************************************************
 *
 *	Area.h
 *
 *	Main header for Area class
 *
 *	Created at:
 *	2012-01-10
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef Area_H_
#define Area_H_

#include <iostream>
#include <string>
using namespace std;


class Area {
private:

	string		description,
				name;

public:
	/**   Constructor section */
	/* default Constructor */
					Area();
	 /* full  Constructor  */
					Area(const string& name, const string& description);
	 /* copy  Constructor*/
					Area(const Area&);
	 /* delete employee */
					~Area();

	/*	 *   end Constructor section	 */
};

#endif
