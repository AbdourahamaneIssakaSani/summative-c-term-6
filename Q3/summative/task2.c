/**
* Task 2:
*
* Looking at the list of all candidates from candidates.txt file,
* some candidates appear more than once hence there is a need remove
* all duplicates and only keep unique candidates.
* Write a program that will take candidates and remove all duplicate names
* Use redirection or pipe to save the output of the executed program into
* answer file named unique_candidate.txt
*/


/**
* Compile:
*      gcc -Wall -Werror -Wextra -pedantic task2.c -o unique_candidates
*
* Usage with pipes and redirection:
*      cat summative/candidates | ./unique_candidates > unique_candidate.txt
*
* will save the output of the program into unique_candidate.txt
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256

int main(void)
{
	char name[MAX_NAME_LENGTH];

	char *names[MAX_NAME_LENGTH];

	int index = 0;

	/*Read names from stdin*/
	while (fgets(name, MAX_NAME_LENGTH, stdin) != NULL)
	{
		/*Remove newline character*/
		name[strlen(name) - 1] = '\0';

		int isDuplicate = 0;

		for (int i = 0; i < index; i++)

		{
			if (strcmp(name, names[i]) == 0)
			{
				isDuplicate = 1;
				break;
			}
		}

		if (!isDuplicate)
		{
			names[index] = strdup(name);
			if (names[index] == NULL)
			{
				perror("Memory allocation error");
				exit(1);
			}
			index++;
		}
	}

	/*Write distinct names to stdout*/
	for (int i = 0; i < index; i++)

	{
		printf("%s\n", names[i]);
		free(names[i]);
	}

	return (0);
}
