#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int is_digit(int c);
int ft_atoi(char *str);
int numbers_unique(int * arr, int len);
int input_valid(char * str);
int word_count(char *str);
int * str_to_numbers(char *str);
int united_str_size(int arg_num, char ** arguments);
char *words_to_str(int argc, char ** argv);