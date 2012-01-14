/******************************************************************************
 *
 *	Colaborador.h
 *
 *	Main header for Colaborador class
 *
 *	Created at:
 *	2012-01-10
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef _COLABORADOR_H_
#define _COLABORADOR_H_

#include <iostream>
#include <sstream>
#include <string>

namespace dmd
{

using std::string;
using std::ostream;

class Colaborador
{
protected:
    string name;		/* name of the employee */
    string address;		/* address of the employee */
    string password;	/* password of the employee */
    string email;		/* email of the employee */

    int	nif;			/* nif of the employee */
    int phone;			/* phone number of the employee */
    double salary;		/* Salary of the employee */

public:

    Colaborador();

	Colaborador(const string& _name, const string& _adress, const string& _email, const string& _password,
			int _nif, int _phone, double _salary);

	Colaborador(const Colaborador&);

	virtual ~Colaborador();

	/**
	 * Returns a perfect copy of the Colaborador.
	 *
	 * @return a copy of Colaborador
	 */
    virtual Colaborador *clone() const;

    // GETTERS
    const std::string& getName() const { return this->name; }
    const string& getAddress() const { return this->address; }
    const string& getEmail() const { return this->email; }
    const string& getPassword() const { return this->password; }
    int getNIF() const { return this->nif; }
    int getPhone() const { return this->phone; }
    double getSalary() const { return this->salary; }

    // SETTERS
    void setName(const string&);
    void setAdress(const string&);
    void setEmail(const string&);
    void setPassword(const string&);
    void setNIF(int);
    void setPhone(int);
    void setSalary(double);

	Colaborador& operator =(const Colaborador&);

	/* test if the employee is the same as the employee @param based in email*/
	/**
	 * Tests if this Colaborador is equal to Colaborador "c", based in their
	 * email.
	 *
	 * @param c a Colaborador to check with
	 * @return true if they're equal, false otherwise
	 */
	bool operator ==(const Colaborador &c);

	/**
	 * Writes the Colaboradar data to the output stream.
	 *
	 * @param out the output stream
	 */
	void write(ostream& out) const;
};

}

/**
 * Operator << overload to allow a Colaborador to be outputted
 * to the output stream (ostream).
 *
 * @param out the output stream to write into
 * @param c the Colaborador to use
 *
 * @return the ostream with the Colaborador data
 */
std::ostream& operator <<(std::ostream &out, const dmd::Colaborador &c);

#endif /* _COLABORADOR_H_ */
