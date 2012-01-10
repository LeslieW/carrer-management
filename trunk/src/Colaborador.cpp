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

using namespace std;
using namespace col;
#include "Colaborador.h"

Colaborador::Colaborador()
{
	this->name = "johnDoe";
	this->salary = 0;
	this->adress = "limbo";
	this->nif = 123456789;
	this->email = "null@no-reply.com";
	this->password = "superHardP455w0d";
}

Colaborador::Colaborador(const string& name, const string& adress, const string& email, const string& password, int nif, int phone, double salary)
{
	this->name = name;
	this->salary = salary;
	this->adress = adress;
	this->nif = nif;
	this->email = email;
	this->password = password;
	this->phone = phone;
}

Colaborador::Colaborador(const Colaborador& copy)
{
	this->name = copy.name;
	this->salary = copy.salary;
	this->adress = copy.adress;
	this->nif = copy.nif;
	this->email = copy.email;
	this->password = copy.password;
	this->phone = copy.phone;
}

Colaborador::~Colaborador() {
}

Colaborador* Colaborador::clone() const {
	return new Colaborador(*this);
}

string Colaborador::getName() const {
	return this->name;
}

string Colaborador::getAdress() const {
	return this->adress;
}

string Colaborador::getEmail() const {
	return this->email;
}
string Colaborador::getPassword() const {
	return this->password;
}

int Colaborador::getNIF() const {
	return this->nif;
}

int Colaborador::getPhone() const {
	return this->phone;
}

double Colaborador::getSalary() const
{
	return this->salary;
}
// list<algo>*	Colaborador::getGroup()const{}

void Colaborador::setName(const string& name)
{
		this->name = name;
}

void Colaborador::setAdress(const string& adress)
{
		this->adress = adress;
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
	this->phone=phone;
}

void Colaborador::setSalary(double salary)
{
	this->salary=salary;
}


Colaborador& Colaborador::operator  = ( const Colaborador& var)
{
    if (this != &var) {
    	this->name = var.name;
    	this->salary = var.salary;
    	this->adress = var.adress;
    	this->nif = var.nif;
    	this->email = var.email;
    	this->password = var.password;
    	this->phone = var.phone;
    }
    return *this;
}

bool Colaborador::operator == ( const Colaborador& var)
{
	if(this->email == var.email)
		return true;
	return false;
}

bool Colaborador::operator <  ( const Colaborador& var)
{
	if(this->salary < var.salary)
		return true;
	return false;
}

bool Colaborador::operator >  ( const Colaborador& var)
{
	if(this->salary > var.salary)
		return true;
	return false;
}

void Colaborador::escreve(ostream& out)const
{
	out<<"Nome: "<< name<<"\nEmail: "<<email<<"\nTelefone: "<<phone<<"\nSalário: "<<salary<<"\nNIF: "<<nif<<endl;
}

ostream& operator <<(ostream& out, const Colaborador& p) {
    p.escreve(out);
    return out;
}

