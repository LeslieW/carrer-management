#include <iostream>
#include <string>
#include <vector>
#include <list>

#include <boost/function.hpp>
#include <boost/bind.hpp>

#include "Menu.h"
#include "MenuEntry.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::list;
using boost::function;
using boost::bind;

using ui::Menu;
using ui::MenuEntry;

Menu::Menu()
{
}

Menu::Menu(const std::string& _header, const list<MenuEntry*>& _options)
{
	header=_header;
	for(list<MenuEntry*>::const_iterator itr=_options.begin();
			itr!=_options.end(); itr++,options.push_front(*itr));
}

Menu::Menu(const Menu& p)
	:header(p.header),
	 options(p.options)
{

	}

Menu::~Menu()
{
}

Menu* Menu::clone() const{
	return new Menu(*this);
}

void Menu::draw() {
	char op;
	char key;
	do {
		//draw menu
		cout << "  ---- MENU ----" << endl;
		cout << header << endl;
		for (list<const MenuEntry*>::iterator itr = options.begin();itr != options.end(); itr++) {
			MenuEntry entry = *(*itr);
			key = entry.getMenuKey();
			cout << key << entry.getName() << endl;
		}
		cout << "0 - Voltar" << endl;
		cout << endl << "Opcção: ";

		cin >> op;

		//option validation
		if (op == '0')
			return;
		if (op >= 'A' && op <= key) {
			char pos = 'A';
			list<const MenuEntry*>::iterator itr = options.begin();
			do {
				//apilication start
				if (pos == op) {
					MenuEntry entry = **itr;
					entry.call();
					return;
				}
				itr++;
			} while (true); //pos != op

		} else {
			cout << endl << endl << endl << endl << endl << endl
					<< "  --- Opcao (" << op << ")Invalida ---" << endl;
		}

	} while (true);

}
