#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

typedef struct profile
{
    char * name;
    char *surname;
    char * number;
    char * email;
    struct profile *next_prof;
}   prof;

int run();