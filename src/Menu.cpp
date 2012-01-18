#include <string>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <list>

#include <boost/function.hpp>
#include <boost/bind.hpp>

#include "Menu.h"
#include "MenuEntry.h"

using std::string;
using std::stringstream;
using std::cout;
using std::cin;
using std::endl;
using std::list;
using boost::function;
using boost::bind;

using ui::Menu;
using ui::MenuEntry;

Menu::Menu(const std::string& _header, const vector<const MenuEntry*>& _options) :
		header(_header), options(_options) {
}

Menu::Menu(const Menu& p) :
		header(p.header), options(p.options) {
}

Menu::~Menu() {
}

Menu* Menu::clone() const {
	return new Menu(*this);
}

void Menu::draw() {
	char op;
	char key;
	bool repeat;

	//generating menu
	stringstream out;
	out << "  ------ MENU ------" << endl;
	out << "  -      " << header << endl;
	int size = options.size();
	for (int i = 0; i < size; i++) {
		MenuEntry entry = *options[i];
		key = entry.getMenuKey();
		out << "-      " << key << "  -    " << entry.getName() << endl;
	}
	out << "  ----      ----" << endl;
	out << "  -    0 - Voltar" << endl;
	out << "  --------------" << endl;
	out << endl << "Opcção: ";
	do {
		//print menu
		cout << out.str();
		cin >> op;

		//option validation
		repeat = true;
		if (op == '0')
			return;
		if (op >= 'A')
		{
			if (op <= key)
			{
				char pos = 'A';
				int i = 0;
				do {
					//apilication start
					if (pos+i == op) {
						MenuEntry entry = *options[i];
						entry.call();
						break;
					}

					i++;
				} while (true); //pos != op

			}else{
				cout << endl << endl << endl << endl << endl << endl
				<< "  --- Invalid Option (" << op << ")" << endl
				<< "  --- Value is higher then expected"<<endl<<endl;
			}
		} else {
			cout << endl << endl << endl << endl << endl << endl
			<< "  --- Invalid Option (" << op << ")" << endl
			<< "  --- Value is smaller then expected"<<endl<<endl;
		}

	} while (repeat);

}
