#include <iostream>
#include <string>
#include <list>

#include <boost/function.hpp>
#include <boost/bind.hpp>

#include "MenuEntry.h"

using std::string;
using std::cout;
using std::endl;
using std::list;
using boost::function;
using boost::bind;

using ui::MenuEntry;

MenuEntry::MenuEntry(const string &_name, const Callback &firstCallBack)
	: name(_name)
{
	callbacks.push_back(firstCallBack);
}

void MenuEntry::call()
{
	for (list<Callback>::const_iterator itr = callbacks.begin(); itr != callbacks.end(); itr++)
	{
		(*itr)();
	}
}

void MenuEntry::pushCallback(const Callback &callback)
{
	callbacks.push_back(callback);
}
