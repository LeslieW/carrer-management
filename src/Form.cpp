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
	for (list<FormEntry>::iterator itr = entries.begin(); itr != entries.end(); itr++)
	{
		FormEntry &entry = *itr;
		if (!entry.write())
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

vector<const string&> Form::getValues()
{
	vector<const string&> ret(entries.size());
	int i = 0;

	for (list<FormEntry>::iterator itr = entries.begin(); itr != entries.end(); itr++, i++)
	{
		FormEntry &entry = *itr;
		ret[i] = entry.getValue();
	}

	return ret;
}
