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

#ifndef COLABORADOR_H_
#define COLABORADOR_H_
#include <string>
#include <sstream>
#include <iostream>
#include <list>

using namespace std;
namespace col {
/*
 *
 */


class Colaborador {
protected:
	/*Personal information of the employee*/
    string      		name,				/* name of the employee */
    					adress,				/* adress of the employee */
    					password,			/* password of the employee */
    					email;				/* email of the employee */

    int					nif,				/* nif of the employee */
    					phone;				/* phone number of the employee */
    double				salary;				/* Salary of the employee */
   // list<acess>			permicoes;

public:
    /*
     *   Constructor section
     */
    					Colaborador();					/* default Constructor of the employee */
    					Colaborador(const string& name,
    								const string& adress,
    								const string& email,
    								const string& password,
    								int   nif,
    								int   phone,
    								double salary);		/* full  Constructor of the employee */
    					Colaborador(const Colaborador&);/* copy  Constructor of the employee */
    					~Colaborador();					/* destroyer of the employee */
    virtual Colaborador*clone() const;					/* clone of the employee */
    /*
     *   end Constructor section
     */

    /*
	*Access section
	*/
    //get's
    virtual string 		getName()const;					/* return the name of the employee */
    virtual string 		getAdress()const;				/* return the adress of the employee */
    virtual string 		getEmail()const;				/* return the Email of the employee */
    virtual string 		getPassword()const;				/* return the password of the employee */
    virtual int 		getNIF()const;					/* return the NIF of the employee */
    virtual int 		getPhone()const;				/* return the phone number of the employee */
    virtual double 		getSalary()const;				/* return the salary number of the employee */
    //virtual list<algo>*	getGroup()const;				/* return the access group number of the employee */

    //set's
    virtual void 		setName		(const string& );	/* set the name of the employee */
    virtual void 		setAdress	(const string& );	/* set the adress of the employee */
    virtual void 		setEmail	(const string& );	/* set the Email of the employee */
    virtual void 		setPassword	(const string& );	/* set the password of the employee */
    virtual void 		setNIF		(int );				/* set the NIF of the employee */
    virtual void 		setPhone	(int);				/* set the phone number of the employee */
    virtual void 		setSalary	(double);			/* set the salary number of the employee */
    //virtual void		getGroup	(list<algo> );		/* set the access group number of the employee */
    /*
     *   END of Access section
     */


    /*  section */

    	/* set the employee into the employee @param*/
        virtual Colaborador&    operator  = ( const Colaborador&);

        /* test if the employee is the same as the employee @param based in email*/
        virtual bool        	operator == ( const Colaborador&);

        /* test if the employee is the smaller as the employee @param based in salary*/
        virtual bool        	operator <  ( const Colaborador&);

        /* test if the employee is the bigger as the employee @param based in salary*/
        virtual bool        	operator >  ( const Colaborador&);

        /* set ostream @param whith the all personal information from employee*/
        virtual void        	escreve(ostream& out)const;

};
}
/* return ostream @param whith the all personal information from employee*/
ostream& operator <<(ostream &out, const Colaborador &p);

#endif /* COLABORADOR_H_ */
