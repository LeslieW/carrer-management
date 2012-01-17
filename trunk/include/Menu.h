/******************************************************************************
 *
 *	MenuEntry.h
 *
 *	Encapsulates a menu entry.
 *
 *	Created at:
 *	2012-01-17
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef _MENU_H_
#define _MENU_H_

#include <iostream>
#include <string>
#include <list>

#include <boost/function.hpp>
#include <boost/bind.hpp>

using std::string;
using std::cout;
using std::endl;
using std::list;
using boost::function;
using boost::bind;

namespace ui
{

class Menu
{
private:
	list<const MenuEntry&> options;			/* list of all menu options */
	string header;							/* small descripion of the menu */


public:

	Menu(const string& _header, const list<MenuEntry&> _options);	/* Default constroctor */

	void draw();							/* prints all menu */





};
}
