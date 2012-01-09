#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "conv.h"

#define MAX_EMPLOYEE_NAME	256
#define MAX_SIZEOF_LINE		(MAX_CATEGORIES * sizeof(int)) * MAX_EMPLOYEE_NAME * sizeof(int)

int main(int argc, char **argv)
{
	// if (argc < 1)
	// {
	// 		printf("Not enough args. Usage: conv <CSV>"
	//		exit(-1);
	// }
	// FILE *fin = fopen(argv[1]);
	FILE *fin = fopen("../tests/funcionario.csv", "w");
	long fileSize = 0;
	employee *employees = NULL;
	char buff[MAX_SIZEOF_LINE] = "\0";

	if (!fin)
	{
		printf("\nError while opening file\n");
		return -1;
	}

	// obtain the number of lines in the file.
	// this will be the number of employees.
	fseek(fin, 0, SEEK_END);
	fileSize = ftell(fin);
	rewind(fin);

	// if file is empty, we shouldn't continue
	if (!fileSize)
	{
		printf("\nFile is empty.\n");
		fclose(fin);
	}

	employees = (employee *) malloc(fileSize * sizeof(employee));

	while (fscanf(fin, "%s", buff) != EOF)
	{
		printf("%s\n", buff);

		memset(buff, '\0', MAX_SIZEOF_LINE);
	}

	return 0;
}

int convReadCSV(FILE *f, employee *employeeList)
{
	return 0;
}

int convWriteBin(FILE *f, employee *employeeList)
{
	return 0;
}
