/******************************************************************************
 *
 *	Menu.h
 *
 *	Encapsulates all menu entry.
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

#include <sstream>
#include <iostream>
#include <string>
#include <list>
#include <vector>

#include <boost/function.hpp>
#include <boost/bind.hpp>
#include "MenuEntry.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::list;
using boost::function;
using boost::bind;

using ui::MenuEntry;
namespace ui
{

class Menu
{
private:
	std::string header;							/* small descripion of the menu */
	vector<const MenuEntry*> options;			/* list of all menu options */

public:

	/* Default constroctor */
	Menu(const std::string& _header, const vector<const MenuEntry*>& _options);

	/* copy constroctor */
	Menu(const Menu& p);

	~Menu();

	/**
	 * Returns a perfect copy of the Menu.
	 *
	 * @return a copy of Menu
	 */
	Menu* clone() const;

	/*
	 *  prints all menu
	 * */
	void draw();


};
}

#endif /* _MENU_H_ */
