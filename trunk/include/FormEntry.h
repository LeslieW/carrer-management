/******************************************************************************
 *
 *	FormEntry.h
 *
 *	Encpasulates a form entry's state (message and value inputted).
 *
 *	Created at:
 *	2012-01-13
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef _FORMENTRY_H_
#define _FORMENTRY_H_

#include <iostream>
#include <string>
#include <exception>

namespace ui
{

class FormEntry
{
private:
	std::string entry;	/* the entry's description */
	std::string value;	/* the value entered in the input */
	bool revalidate;	/* flag to revalidade input */

	void obtainInput();

public:

	FormEntry(const std::string &_entry, bool _revalidate);

	/**
	 * Writes to STDOUT. If revalidation is active, runs the
	 * revalidation loop.
	 *
	 * @return true if revalidate is off or the user accepts
	 * his input, false otherwise
	 */
	bool write();

	// GETTERS
	const std::string& getValue() const { return value; }
};

}

#endif /* _FORMENTRY_H_ */
