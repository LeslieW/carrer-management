#include "FormEntry.h"

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using ui::FormEntry;

FormEntry::FormEntry(const string &_entry, bool _revalidate = false)
	: entry(_entry), value(""), revalidate(_revalidate)
{}

void FormEntry::obtainInput()
{
	cout << endl << entry << endl << "$ ";
	cin >> value;
}

bool FormEntry::write()
{
	bool b = revalidate;

	obtainInput();

	if (revalidate)
	{
		char c;

		do
		{
			cout << "Are you sure about this value (Y/N/A): " << endl << "$ ";
			cin >> c;

			switch (c)
			{
			case 'Y':
				return true;

			case 'A':
				return false;

			case 'N':
			default:
				break;
			}

			obtainInput();
			cout << endl;

		} while (true);
	}

	return true;
}

