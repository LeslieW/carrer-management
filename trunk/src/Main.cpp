/******************************************************************************
 *
 *	main.cpp
 *
 *	Development file for main class
 *
 *	Created at:
 *	2012-01-10
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/
#include <string>
#include <sstream>
#include <iostream>
#include <list>
#include <boost/function.hpp>
#include <boost/bind.hpp>

using std::string;
using std::cout;
using std::endl;
using std::list;
using boost::function;
using boost::bind;

#include "MenuEntry.h"
#include "Menu.h"
#include "Colaborador.h"

using ui::MenuEntry;
using ui::Menu;
using dmd::Colaborador;

typedef function<void()> Callback;
#include "Colaborador.h"

namespace test {
void funcion1(const string& text) {
	cout << endl << text << endl << endl;
	Colaborador test_1("My name", "MyAdress", "My Email@place.xxx",
			"My!Super#pass", 123123123, 931232343, 500.34f);
	cout<< test_1<<endl;

}
}

using test::funcion1;

int main() {


	char key = 'A';
	vector<const MenuEntry*> options;
	options.push_back(new MenuEntry(key, "Descricao do menu x1",
					boost::bind(&test::funcion1, "whf")));
	key++;
	options.push_back(new MenuEntry(key, "Descricao do menu x2",
					boost::bind(&test::funcion1, "whf versio2")));
	Menu menu1("Menu principal", options);
	menu1.draw();
	return 1;
}

