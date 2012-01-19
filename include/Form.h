/******************************************************************************
 *
 *	Form.h
 *
 *	Encpasulates a form state (list of form entries).
 *
 *	Created at:
 *	2012-01-13
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef _FORM_H_
#define _FORM_H_

#include <iostream>
#include <string>
#include <list>
#include <vector>

#include "FormEntry.h"

namespace ui
{

using std::string;
using std::cout;
using std::endl;
using std::list;
using std::vector;
using ui::FormEntry;

class Form
{
private:
	list<FormEntry> entries;	/* list of entries in the form */

public:
	Form();

	Form(const list<FormEntry> &_entries);

	~Form();

	/**
	 * Opens the form and runs through its options.
	 *
	 * @return true if the form was accepted by the user,
	 * false otherwise
	 */
	bool show();

	/**
	 * Pushes a new entry into the list of form entries.
	 *
	 * @param entry the entry to push
	 */
	void pushEntry(const FormEntry &entry);

	/**
	 * Returns a vector with the values the form read.
	 *
	 * @return the vector with the values the form read
	 */
	vector<std::string> getValues();



};

}

#endif /* _FORM_H_ */
