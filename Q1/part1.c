/**
* Q1.
* Case Study: MoMo Pin generation and cracking.
*
* People are using mobile money to receive and send money, the security
* of their money depends on the PIN (Personal Identification Number).
* John is interested in finding all possible combinations of PINs that
* are used by MoMo clients.
*
* Business Rules:
* Each PIN is a five digit number
* Each digit slot has an equal possibility of being occupied by 10 digits
* [from 0 to 9 all inclusive].
*
* Expected Tasks:
* Part I: Write a program that completes the following tasks.
* You will generate all PINs satisfying the business rules.
* All generated PINs will be recorded in a file named generated_passwords.txt
* in the same directory as the executing program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 5
#define MAX_DIGIT_VALUE 9
#define MIN_DIGIT_VALUE 0

void generatePins(int *pin, int index, FILE *file);

void printPin(int *pin, FILE *file);

/**
* main - Entry point
*
* Return: Always 0 (Success)
*/
int main(void)
{
	FILE *file = fopen("generated_passwords.txt", "w");

	if (file == NULL)
    {
		printf("Error opening file!\n");
		exit(1);
	}


	int pin[MAX_DIGITS];

	generatePins(pin, 0, file);
	fclose(file);

	return (0);
}

/**
* generatePins - generates all possible PINs
* @pin: array of digits
* @index: index of the array
* @file: file to write to
*
* Return: void
*/
void generatePins(int *pin, int index, FILE *file)
{
	if (index == MAX_DIGITS)
	{
		printPin(pin, file);
		return;
	}
	for (int i = MIN_DIGIT_VALUE; i <= MAX_DIGIT_VALUE; i++)

	{
		pin[index] = i;
		generatePins(pin, index + 1, file);
	}
}

/**
* printPin - prints a PIN
* @pin: array of digits
* @file: file to write to
*
* Return: void
*/
void printPin(int *pin, FILE *file)
{
	for (int i = 0; i < MAX_DIGITS; i++)

	{
		fprintf(file, "%d", pin[i]);
	}
	fprintf(file, "\n");
}
