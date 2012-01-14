/******************************************************************************
 *
 *	RH.cpp
 *
 *	Development file for RH class
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

#include "Colaborador.h"
#include "RH.h"

using std::string;
using dmd::Colaborador;
using dmd::RH;

RH::RH() : Colaborador()
{}

RH::RH(const string& name, const string& adress, const string& email, const string& password, int nif, int phone, double salary)
	: Colaborador(name, adress, email, password, nif, phone, salary)
{}

RH::RH(const RH& copy)
	: Colaborador(copy)
{}

RH::~RH()
{}

