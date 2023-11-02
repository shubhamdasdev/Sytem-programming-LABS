/* This is a reference library designed to facilitate file reading.

Shubham Das
11/1/2023 
*/

#include <stdlib.h>
#include <stdio.h>
#include "readfile.h"

FILE *file;

int read_float(float *x)
{
    // This function is merely a placeholder for the time being as I don't utilise it.
    return 1;
}

int read_int(char x[], int option, int* var)
{
    int a,b;
    char c[64],d[64];
    if (option == 1)
    {
        sscanf(x, "%d %s %s %d", var, c, d, &b);
    }
    else
    {
        sscanf(x, "%d %s %s %d", &a, c, d, var);
    }
    return 0;
}

int read_string(char x[], int option, char y[])
{
    int a,b;
    char c[64],d[64];
    if (option == 1)
    {
        sscanf(x, "%d %s %s %d", &a, y, d, &b);
    }
    else
    {
        sscanf(x, "%d %s %s %d", &a, c, y, &b);
    }
    return 0;

}

int open_file(char* inputfile)
{
    file = fopen(inputfile, "r");
    if (file == 0) //fopen returns 0, the NULL pointer, on failure 
    {
        return -1; 
    }
    else 
    {
        return 0;
    }
} 

void close_file()
{
    fclose(file);
}