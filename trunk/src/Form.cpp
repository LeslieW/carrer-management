#include <iostream>
#include <string>
#include <list>
#include <vector>

#include "Form.h"
#include "FormEntry.h"

using std::string;
using std::cout;
using std::endl;
using std::list;
using std::vector;

using ui::Form;
using ui::FormEntry;

Form::Form()
	: entries()
{}

Form::Form(const list<FormEntry> &_entries)
	: entries(_entries)
{}

Form::~Form()
{
	entries.clear();
}

bool Form::show()
{
	for (list<FormEntry>::const_iterator itr = entries.begin(); itr != entries.end(); itr++)
	{
		if (!(*itr).write())
		{
			cout << "Will exit form" << endl;

			return false;
		}
	}

	return true;
}

void Form::pushEntry(const FormEntry &entry)
{
	entries.push_back(entry);
}

const vector<const string&> Form::getValues() const
{
	vector<const string&> ret(entries.size());
	int i = 0;

	for (list<entries>::const_iterator itr = entries.begin(); itr != entries.end(); itr++, i++)
	{
		ret[i] = (*itr).getValue();
	}

	return ret;
}
