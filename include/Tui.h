/******************************************************************************
 *
 *	Tui.cpp
 *
 *	This class is responsable for the Tex unit interface
 *
 *	Created at:
 *	2012-01-18
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
#include "Form.h"
#include "FormEntry.h"
#include "DataAccessLayer.h"

using ui::MenuEntry;
using ui::Menu;
using dmd::Colaborador;
using ui::FormEntry;
using ui::Form;
using core::DataAccessLayer;


typedef function<void()> Callback;
typedef unsigned int ColaboradorId;
#include "Colaborador.h"


namespace ui
{
class Tui{
public:

	/*
	 *  Default constroctor
	 *  Build the start interface
	 */
	Tui();

	~Tui();

	/*
	 * Initiates this class and all components
	 */
	void static run();

	/*
	 *  Login for user
	 */
	vector<dmd::Operacao> login(ColaboradorId id);

	void executarOperacao(int id);






};
}
