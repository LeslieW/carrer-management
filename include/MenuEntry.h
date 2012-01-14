/******************************************************************************
 *
 *	MenuEntry.h
 *
 *	Encapsulates a menu entry.
 *
 *	Created at:
 *	2012-01-13
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef _MENUENTRY_H_
#define _MENUENTRY_H_

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

class MenuEntry
{
private:
	typedef function<void ()> Callback;

	list<Callback> callbacks;	/* list of callbacks to execute */
	string name;						/* name of the menu entry */

public:
	MenuEntry(const string &_name, const Callback &firstCallBack);

	/**
	 * Executes all the callbacks.
	 */
	void call();

	/**
	 * Pushes a new callback into the list.
	 *
	 * @param callback the callback to push
	 */
	void pushCallback(const Callback &callback);
};

}

#endif /* _MENUENTRY_H_ */
