/******************************************************************************
 *
 *	app.h
 *
 *	Main header for the PDA application (point a.2 from part 4.2)
 *
 *	Created at:
 *	2012-01-11
 *
 *	Author(s):
 *
 *		B5-8 LAPRIII group
 *
 *****************************************************************************/
#ifndef _APP_H_
#define _APP_H_

#include <stdio.h>
#include <stdlib.h>

#include "conv.h"

typedef unsigned int category;

// for use in the assembly modules
const int max_employee_name = MAX_EMPLOYEE_NAME;
const int max_categories = MAX_CATEGORIES;

/**
 * Loads the data from the binary into an array of employees.
 *
 * @param f the file to read from [IN]
 * @param employeeList the array of employees to load into [OUT]
 * @param numEmployees the number of employees [IN]
 * @return < 0 for errors, >= 0 if successful
 */
int appReadBinFile(FILE *f, employee *employeeList, unsigned int numEmployees);

/**
 * Loads the categories from an employee into an array
 * of categories.
 *
 * @param employee the employee data (struct) [IN]
 * @param categories an array of categories to load into [OUT]
 */
void appLoadCategories(void* employee, category *categories);

/**
 * Gets the current category from an employee.
 *
 * @param employee the employee data (struct) [IN]
 * @param currCategory the current category [OUT]
 */
void appGetCurrentCategory(void *employee, category *currCategory);

/**
 * Counts the number of categories an employee has been through.
 *
 * @param employee the employee data (struct) [IN]
 * @param count the count of categories [OUT]
 */
void appCountCategories(void *employee, int *count);

/**
 * Counts the number of employees in a given category.
 *
 * @param employees the array of employee data [IN]
 * @param _category the category to filter the employees [IN]
 * @param count the count of employees in the category [OUT]
 */
void appNumEmployeesInCategory(void **employees, category _category, int *count);

#endif /* _APP_H_ */
