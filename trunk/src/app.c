#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conv.h"
#include "app.h"

int main(int argc, char **argv)
{
	FILE *fin = NULL;

	employee *employees = NULL;
	unsigned int numEmployees = 0;

	category *categories = NULL;

	int i = 0, j = 0;
	int count = 0;
	category tmpCategory = 0;

	if (argc < 1)
	{
		printf("\nNot enough args. Usage: app <input_file>\n");
		exit(-1);
	}

	if (! (fin = fopen(argv[1], "r")) )
	{
		printf("\nError while opening file\n");

		// with exit -1, no house keeping is needed, the OS
		// will free the VA space of the whole process
		exit(-1);
	}

	if (fread(&numEmployees, sizeof(unsigned int), 1, fin) != 1)
	{
		printf("\nERROR while reading header section\n");

		fclose(fin);
		exit(-1);
	}

	employees = (employee *) malloc(numEmployees * sizeof(employee));
	categories = (category *) malloc(MAX_CATEGORIES * sizeof(category));

	appReadBinFile(fin, employees, numEmployees);
	fclose(fin);

	for (; i < numEmployees; i++)
	{
		appLoadCategories(&employees[i], categories);

		// print categories of employee
		printf("\nemployee number %d, has the following categories:\n", employees[i].number);
		for (j = 0; j < MAX_CATEGORIES; j++)
		{
			if (categories[j])
				printf("%d, ", j);
		}

		appGetCurrentCategory(&employees[i], &tmpCategory);

		// print current category
		printf("\ncurrent category %d\n", tmpCategory);
		 
		appCountCategories(&employees[i], &count);

		// print the number of categories of current employee
		printf("\nnumber of categories of employee: %d\n", count);
		 
		appNumEmployeesInCategory(employees, tmpCategory, &count);

		// print the number of employees in this employee's category
		printf("\nnumber of employees in category %d: %d\n\n;;;;;;;;;;;;;;;;;;;;\n", tmpCategory, count);
		

		memset(categories, 0, MAX_CATEGORIES * sizeof(category));
	}

	// house keeping
	if (employees)
		free(employees);
	//if (categories)
		//free(categories);
	return 0;
}

int appReadBinFile(FILE *f, employee *employeeList, unsigned int numEmployees)
{
	int i = 0;

	while (!feof(f) && i < numEmployees)
	{
		if (fread(&employeeList[i++], sizeof(employee), 1, f) != 1)
		{
			printf("\nERROR reading employee, skipping...\n");
		}
	}

	return 0;
}
