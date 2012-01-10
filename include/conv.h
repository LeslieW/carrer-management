/******************************************************************************
 *
 *	conv.h
 *
 *	Main header for the CSV converter (point a.1 from part 4.2)
 *
 *	Created at:
 *	2012-01-09
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/

#ifndef _CONV_H_
#define _CONV_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *cat_delimiter = "->";	/* global category delimiter */

#define MAX_CATEGORIES			32
#define DELIMITER				";"
#define MAX_EMPLOYEE_NAME		256

/**
 * The employee struct will hold a tokenized line from the CSV file.
 */
typedef struct _employee
{
	unsigned int number;			/* number of the employee */
	char name[MAX_EMPLOYEE_NAME];	/* name of the employee */
	unsigned int categories;		/* categories flags */
} employee;

/**
 * Loads and fills an employee data from a given CSV line,
 * representing an employee.
 *
 * @param data the CSV line representing an employee [IN]
 * @return an employee
 */
employee convLoadEmployee(char *data);

/**
 * Reads a CSV file, using a given FILE handle.
 *
 * @param f the FILE handle [IN]
 * @param employeeList the array of employees to fill with the CSV data [OUT]
 * @return < 0 if an error occurs, else returns the number of employees read
 */
int convReadCSV(FILE *f, employee *employeeList);

/**
 * Writes the employee data into a binary file, using a given FILE handle.
 *
 * @param f the FILE handle [IN]
 * @param employeeList the array of employees to serialize [IN]
 * @param numEmployees the number of employees in the array [IN]
 * @return 0 if successfull, > 0 if internal error or < 0 if system
 * 		error (memory, permissions, etc...)
 */
int convWriteBin(FILE *f, employee *employeeList, unsigned int numEmployees);

#endif // _CONV_H_
