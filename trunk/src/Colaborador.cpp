/******************************************************************************
 *
 *	Colaborador.cpp
 *
 *	Development file for Colaborador class
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

#include "Colaborador.h"

using std::string;
using dmd::Colaborador;

Colaborador::Colaborador()
{}

Colaborador::Colaborador(const string& _name, const string& _adress, const string& _email, const string& _password,
		int _nif, int _phone, double _salary) :
		name(_name),
		address(_adress),
		email(_email),
		password(_password),
		nif(_nif),
		phone(_phone),
		salary(_salary)
{}

Colaborador::Colaborador(const Colaborador& copy)
{
	this->name = copy.name;
	this->salary = copy.salary;
	this->address = copy.address;
	this->nif = copy.nif;
	this->email = copy.email;
	this->password = copy.password;
	this->phone = copy.phone;
}

Colaborador::~Colaborador()
{}

Colaborador* Colaborador::clone() const
{
	return new Colaborador(*this);
}

void Colaborador::setName(const string& name)
{
	this->name = name;
}

void Colaborador::setAdress(const string& adress)
{
	this->address = adress;
}

void Colaborador::setEmail(const string& email)
{
	this->email = email;
}

void Colaborador::setPassword(const string& password)
{
	this->password = password;
}

void Colaborador::setNIF(int nif)
{
	this->password = password;
}

void Colaborador::setPhone(int phone)
{
	this->phone = phone;
}

void Colaborador::setSalary(double salary)
{
	this->salary = salary;
}


Colaborador& Colaborador::operator =(const Colaborador& var)
{
    if (this != &var)
    {
    	this->name = var.name;
    	this->salary = var.salary;
    	this->address = var.address;
    	this->nif = var.nif;
    	this->email = var.email;
    	this->password = var.password;
    	this->phone = var.phone;
    }
    return *this;
}

bool Colaborador::operator ==(const Colaborador& var)
{
	return this->email == var.email;
}

void Colaborador::write(ostream& out) const
{
	out << "Nome: " << name << std::endl
		<< "Email: " << email << std::endl
		<< "Telefone: " << phone << std::endl
		<< "Salario: " << salary << std::endl
		<< "NIF: " << nif << std::endl;
}

std::ostream& operator <<(std::ostream& out, const Colaborador& c)
{
    c.write(out);
    return out;
}

