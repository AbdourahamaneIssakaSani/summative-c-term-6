/**
* Part II: Write a program that completes the following tasks
*
* John is interested in testing weakness of different PINs in
* such a way that the PIN is feed to the program and the program
* compare that PIN against all PINs stored in the generated_passwords.txt.
* The program will generate the probability of finding that PIN in the file.
*
* Hint: Consider the number of iterations to access the PIN John feed
* to the system to test against the total number of all possible
* iterations in the file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DIGITS 5
#define MAX_DIGIT_VALUE 9
#define MIN_DIGIT_VALUE 0


int is_numeric(char *str);

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(void)
{
	FILE *file = fopen("generated_passwords.txt", "r");

	if (file == NULL)
	{
		printf("Error opening file!\n");
		exit(1);
	}

	char pin[MAX_DIGITS + 1];

	int totalCombinations = 1;

	int position = 0;

	for (int i = 0; i < MAX_DIGITS; i++)
	{
		totalCombinations *= (MAX_DIGIT_VALUE - MIN_DIGIT_VALUE + 1);
	}

	printf("Enter PIN: ");
	if (scanf("%5s", pin) != 1 || strlen(pin) != MAX_DIGITS || !is_numeric(pin))
	{
		printf("Invalid input. Please enter a 5-digit PIN.\n");
		fclose(file);
		return (1);
	}

	char temp[MAX_DIGITS + 1];

	while (fscanf(file, "%s", temp) == 1)
	{
		position++;

		if (strcmp(pin, temp) == 0)
		{
			break;
		}
	}

	if (totalCombinations > 0)
	{
		float probability =

		(float)(totalCombinations - position) / (float)totalCombinations;

		printf("Iteration: %d\n", position);
		printf("Probability: %f\n", probability);

	}

	fclose(file);

	return (0);
}


/**
* is_numeric - checks if a string is numeric
* @str: string to check
* Return: 1 if numeric, 0 otherwise
*/
int is_numeric(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (!isdigit(str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
