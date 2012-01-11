#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conv.h"

#define INITIAL_EMPLOYEES	100		/* the initial size of the employee array */
#define EMPLOYEE_INCREMENT	10		/* the number of employees to add, when the array reaches its boundaries */
#define MAX_SIZEOF_LINE		(MAX_CATEGORIES * sizeof(int)) * MAX_EMPLOYEE_NAME * sizeof(int)

int main(int argc, char **argv)
{
	FILE *fin = NULL;
	FILE *fout = NULL;
	employee *employees = NULL;				/* employee array */
	int numEmployees = INITIAL_EMPLOYEES;	/* the number of employees loaded */

	// display the correct usage, if the arguments to the
	// application are missing
	if (argc < 2)
	{
		printf("\nNot enough args. Usage: conv <input_file> <output_file>\n");
		exit(-1);
	}
	
	// attempt to open the files
	if (!(fin = fopen(argv[1], "r")) || !(fout = fopen(argv[2], "w")))
	{
		printf("\nError while opening file\n");
		
		// with exit -1, no house keeping is needed, the OS
		// will free the VA space of the whole process
		exit(-1);
	}

	employees = (employee *) malloc(numEmployees * sizeof(employee));

	numEmployees = convReadCSV(fin, employees);

	convWriteBin(fout, employees, numEmployees);

	// house keeping
	free(employees);
	fclose(fin);
	fclose(fout);
	return 0;
}

employee convLoadEmployee(char *data)
{
	char *token = NULL;
	employee ret;
	
	// we initialize the employee to 0
	memset(&ret, 0, sizeof(employee));

	if (!data)
	{
		return ret;
	}

	// get the number of the employee
	token = strtok(data, DELIMITER);
	ret.number = atoi(token);

	// get the name of the employee
	token = strtok(NULL, DELIMITER);
	strcpy(ret.name, token);

	// build flag integer with past categories
	token = strtok(NULL, DELIMITER);
	while (token)
	{
		// each bit represents a category. If a
		// bit is active, that category belongs in
		// the employee's career
		ret.categories |= 1 << atoi(token);
		
		token = strtok(NULL, cat_delimiter);
	}

	return ret;
}

int convReadCSV(FILE *f, employee *employeeList)
{
	char buff[MAX_SIZEOF_LINE] = "\0";
	int i = 0;
	employee tmp;
	employee *tmpEmployees = NULL;	/* auxiliary pointer used to reallocate the employee array */

	unsigned int currNumberEmployees = INITIAL_EMPLOYEES;

	while (fscanf(f, "%s", buff) != EOF)
	{
		// load employee from a CSV file line
		tmp = convLoadEmployee(buff);

		// check if the data was correct
		if (tmp.number > 0 && tmp.name)
		{
			// increase the array size if we reached the limit
			if (i >= currNumberEmployees)
			{
				tmpEmployees = realloc(employeeList, EMPLOYEE_INCREMENT);

				// if no pointer is returned, there is no memory available
				if (!tmpEmployees)
				{
					printf("\nFATAL ERROR adding employee: No memory available\n");
					exit(-1);
				}

				// if the address is different from the original, a new
				// address was allocated. We free the old one and point to
				// the new one.
				if (tmpEmployees != employeeList)
				{
					free(employeeList);
					employeeList = tmpEmployees;
				}
			}

			employeeList[i] = tmp;
		}
		else
		{
			printf("\nERROR while loading employee at line %d\n", i);
		}

		i++;
		memset(buff, '\0', MAX_SIZEOF_LINE);
	}

	return i;
}

int convWriteBin(FILE *f, employee *employeeList, unsigned int numEmployees)
{
	int r = 0;	/* return value */

	r = fwrite(employeeList, sizeof(employee), numEmployees, f);

	/**
	 * fwrite returns the number of elements written. If
	 * it differs from numEmployees, an error occurred.
	 */
	if (r != numEmployees)
	{
		printf("\nERROR writing employees\n");
		return -1;
	}

	return 0;
}
