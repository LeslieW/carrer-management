/******************************************************************************
 *
 *	RH.h
 *
 *	Main header for RH class
 *
 *	Created at:
 *	2012-01-10
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef _RH_H_
#define _RH_H_

#include <iostream>
#include <string>

#include "Colaborador.h"

using std::string;
using dmd::Colaborador;

namespace dmd
{

class RH : public Colaborador
{
public:
	RH();

	RH(const string& name, const string& adress, const string& email, const string& password,
		int nif, int phone, double salary);

	RH(const RH&);

	~RH();
};

}

#endif /* _RH_H */
