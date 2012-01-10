#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct employee
	{
		unsigned int number;
		char name[256];
		unsigned int cats;
	};

	FILE *f = fopen("./out.bin", "r");
	int aux = 0;

	struct employee emp;
	fread(&emp, sizeof(emp), 1, f);
	while (!feof(f))
	{
		printf("\n\tnumber = %d\n \
			name = %s\n \
			categories = %x\n",
			emp.number,
			emp.name,
			emp.cats);
		fread(&emp, sizeof(emp), 1, f);
	}
	
	fclose(f);
	return 0;
}
