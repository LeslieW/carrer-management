/******************************************************************************
 *
 *	DirectorRH.cpp
 *
 *	Development file for DirectorRH class
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

using namespace std;
using namespace col;
#include "Colaborador.h"
#include "DirectorRH.h"

DirectorRH::DirectorRH()
:DirectorRH()
{
}

DirectorRH::DirectorRH(const string& name, const string& adress, const string& email, const string& password, int nif, int phone, double salary)
:DirectorRH(name, adress, email, password, nif, phone, salary)
{
}

DirectorRH::DirectorRH(const DirectorRH& copy)
:DirectorRH(copy)
{
}

DirectorRH::~DirectorRH()
{
}

