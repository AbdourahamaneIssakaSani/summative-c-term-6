/**
 * Q3.
 *
 * S&T Suppliers is hiring for the new roles in the company, the details
 * are found in the this directoryLinks to an external site. You are
 * required to clone the repository and complete the tasks that follows:
 *
 * Task 1:
 * You are required to write a program that will iterate through the directory
 * and list all it contains:
 *
 * For every entry, it will display whether it is a file or a directory.
 * Along with the type, it will display the file name or directory name.
 * Along with the type and the name, it will present the size of each file/directory.
 * If there is any file/directory whose size is zero (0), make sure that you have it deleted.
 * The code to delete such file should be there.
 * Your code should keep an eye on .sh file and delete immediately without opening them.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_PATH 1024

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    char path[MAX_PATH];

    dir = opendir(".");

    if (dir == NULL)
    {
        printf("Error opening directory\n");
        exit(1);
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        sprintf(path, "%s/%s", ".", entry->d_name);

        if (stat(path, &fileStat) < 0)
        {
            printf("Error getting file stats\n");
            exit(1);
        }

        if (S_ISREG(fileStat.st_mode))
        {
            printf("File: %s\n", entry->d_name);
            printf("Size: %ld bytes\n", fileStat.st_size);
            if (fileStat.st_size == 0 || strstr(entry->d_name, ".sh") != NULL)
            {
                printf("Deleting file: %s\n", entry->d_name);
                remove(entry->d_name);
            }
        }
        else if (S_ISDIR(fileStat.st_mode))
        {
            printf("Directory: %s\n", entry->d_name);
            printf("Size: %ld bytes\n", fileStat.st_size);
            if (fileStat.st_size == 0)
            {
                printf("Deleting directory: %s\n", entry->d_name);
                rmdir(entry->d_name);
            }
        }
        else
        {
            printf("Unknown file type: %s\n", entry->d_name);
        }
    }

    closedir(dir);

    return (0);
}
