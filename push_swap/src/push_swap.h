#define MIN -2147483648
#define MAX 2147483647

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "../../ft_printf/ft_printf.h"

/*   Stack structure  */
typedef struct structure_stack
{
    long content;
    struct structure_stack *next;

} t_stack;


/*   Valid input check  */
int is_digit(int c);
long ft_atol(char *str);
int longs_unique(long * arr, int len);
int input_valid(char * str);
int word_count(char *str);
long * str_to_numbers(char *str);
int united_str_size(int arg_num, char ** arguments);
char *words_to_str(int argc, char ** argv);

/*   Operations  */

void swap(t_stack **stck, char stck_name);
void double_swap(t_stack **a, t_stack **b);
void push(t_stack **src, t_stack **dest, char dest_name);
void rotate(t_stack **stck, char stck_name);
void double_rotate(t_stack **a, t_stack **b);
void reverse_rotate(t_stack **stck, char stck_name);
void double_reverse_rotate(t_stack **a, t_stack **b);