/*Q4
Given an array of students's grades
grades = {23, 45, 31, 36, 32, 26, 29, 30, 33, 35, 28,37,19,20}.
You are required to write a program that completes the ascending order
and the descending order of the grades. To complete the task you are
required to use function pointers. Upon running the program, the user is
expected to enter order choice (asc for ascending and desc for descending).

Note that, as you are handling ordering functions, function pointer(s)
are used.
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 14


typedef void (*sortfunc)(int *, int);

void asc(int *grades, int size);

void desc(int *grades, int size);

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(void)
{
	int grades[SIZE] = {23, 45, 31, 36, 32, 26, 29, 30, 33, 35, 28, 37, 19, 20};

	int *ptr = grades;

	sortfunc order[] = {asc, desc};

	int choice;

	printf("Enter order choice:\n");
	printf("1. asc\n");
	printf("2. desc\n");

	scanf("%d", &choice);

	if (choice == 1)
	{
		order[0](ptr, SIZE);
	}
	else if (choice == 2)
	{
		order[1](ptr, SIZE);
	}
	else
	{
		printf("Invalid choice\n");
	}

	return (0);
}

/**
* asc - Sorts an array of integers in ascending order
* @grades: Array of integers
* @size: Size of the array
* Return: Nothing
*/
void asc(int *grades, int size)
{
	int i, j, temp;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if (grades[j] > grades[j + 1])
			{
				temp = grades[j];
				grades[j] = grades[j + 1];
				grades[j + 1] = temp;
			}
		}
	}

	printf("Grades in ascending order:\n");

	for (i = 0; i < size; i++)
	{
		printf("%d ", grades[i]);
	}

	printf("\n");
}

/**
* desc - Sorts an array of integers in descending order
* @grades: Array of integers
* @size: Size of the array
* Return: Nothing
*/
void desc(int *grades, int size)
{
	int i, j, temp;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if (grades[j] < grades[j + 1])
			{
				temp = grades[j];
				grades[j] = grades[j + 1];
				grades[j + 1] = temp;
			}
		}
	}

	printf("Grades in descending order:\n");

	for (i = 0; i < size; i++)
	{
		printf("%d ", grades[i]);
	}

	printf("\n");
}

