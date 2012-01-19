#include <string>
#include <sstream>
#include <iostream>
#include <list>
#include <boost/function.hpp>
#include <boost/bind.hpp>
using core::DataAccessLayer;

using std::string;
using std::cout;
using std::endl;
using std::list;
using boost::function;
using boost::bind;
using core::DataAccessLayer;

#include "MenuEntry.h"
#include "Menu.h"
#include "Colaborador.h"
#include "Form.h"
#include "FormEntry.h"
#include "Tui.h"

using ui::MenuEntry;
using ui::Menu;
using std::cin;
using dmd::Colaborador;
using ui::FormEntry;
using ui::Form;
using ui::Tui;


typedef function<void()> Callback;
typedef unsigned int ColaboradorId;
#include "Colaborador.h"


Tui::Tui()
{
	cout << endl<<" Qual o seu ID:"<<endl;
	ColaboradorId op;
	cin >> op;
	vector<dmd::Operacao> _ops;

	_ops = login(op);
	vector<MenuEntry*> options;

	char key = 'A';
	for(int i= 0; i< options.size(); i++)
	{
		options.push_back(new MenuEntry(key, _ops[i].description, boost::bind(&executarOperacao, _ops[i].opId)));
		key++;
	}

	Menu menu("Menu principal", options);
	menu.draw();
	options.clear();

}

Tui::~Tui()
{
}


void static Tui::run(){
{
	Tui start();
}


vector<dmd::Operacao> Tui::login(ColaboradorId id)
{
	Colaborador col = DataAccessLayer::instance()->getColaborador(id);

	vector<dmd::Operacao> teste;

	return teste;
}

void executarOperacao(dmd::Operacao op){
	switch(op.getOpId()){
	case 1://visalisar beneficios
	{
		cout<<endl<<op.getDescription()<<endl;
		list<FormEntry> entries;
		FormEntry l1("Qual o seu nome: ", false);
		FormEntry l2("Qual o seu email: ", false);
		FormEntry l3("Qual o NIF: ", false);
		FormEntry l4("Qual a password: ", false);
		FormEntry l5("Qual o seu telefone: ", false);
		FormEntry l6("Qual o seu salario: ", false);
		entries.push_back(l1);
		entries.push_back(l2);
		entries.push_back(l3);
		entries.push_back(l4);
		entries.push_back(l5);
		entries.push_back(l6);
		Form _form(entries);
		_form.show();
		break;
	}
	case 2://aprovar progressao
	{
		break;
	}
	case 3:// ver categoria colaborador
	{
		break;
	}
	case 4://submetetr proposta de progressao
	{
		break;
	}
	case 5://Submeter proposta de alteração de beneficios
	{
		break;
	}

	default:
	{
		cout<<endl<<" -    INTERNAL ERROR!"<<endl;
		break;
	}
	}




	}
}

}




