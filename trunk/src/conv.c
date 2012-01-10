#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conv.h"

#define INITIAL_EMPLOYEES	100		/* the initial size of the employee array */
#define EMPLOYEE_INCREMENT	10		/* the number of employees to add, when the array reaches its boundaries */
#define MAX_SIZEOF_LINE		(MAX_CATEGORIES * sizeof(int)) * MAX_EMPLOYEE_NAME * sizeof(int)

int main(int argc, char **argv)
{
	// if (argc < 2)
	// {
	// 		printf("Not enough args. Usage: conv <input_file> <output_file>"
	//		exit(-1);
	// }
	// FILE *fin = fopen(argv[1]);
	FILE *fin = fopen("../tests/funcionario.csv", "r");
	// FILE *fout = fopen(argv[2]);
	FILE *fout = fopen("./out.bin", "w");
	employee *employees = NULL;
	int numEmployees = INITIAL_EMPLOYEES;

	if (!fin || !fout)
	{
		printf("\nError while opening file\n");
		return -1;
	}

	employees = (employee *) malloc(numEmployees * sizeof(employee));

	numEmployees = convReadCSV(fin, employees);

	convWriteBin(fout, employees, numEmployees);

	free(employees);
	fclose(fin);
	fclose(fout);
	return 0;
}

employee convLoadEmployee(char *data)
{
	char *token = NULL;
	employee ret;
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
		ret.categories |= atoi(token)	;
		token = strtok(NULL, cat_delimiter);
	}

	return ret;
}

int convReadCSV(FILE *f, employee *employeeList)
{
	char buff[MAX_SIZEOF_LINE] = "\0";
	int i = 0;
	employee tmp;
	employee *tmpEmployees = NULL;

	static unsigned int currNumberEmployees = INITIAL_EMPLOYEES;

	while (fscanf(f, "%s", buff) != EOF)
	{
		// load employee from a CSV file line
		tmp = convLoadEmployee(buff);

		// check if the data was correct
		if (tmp.number > 0 && tmp.name)
		{
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
