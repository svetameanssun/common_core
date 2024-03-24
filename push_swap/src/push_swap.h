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
    int target;
    int position;
    int cost_a;
    int cost_b;
    int cost;
    struct structure_stack *next;

} t_stack;

/*   Error and Free  */

int ft_error();
void	free_stack(t_stack **head);

/*      NUMBERS     */
int ft_abs(int num);
long ft_atol(char *str);
int stack_contents_mean(t_stack ** stck);

/*   Valid input check  */

int is_digit(int c);
int is_space(int c);
int end_or_space(int c);
int plus_or_minus(int c);

int longs_unique(long * arr, int len);
int input_valid_str(char * str);
int	input_valid_word(char *str);
int word_count(char *str);
t_stack	*str_to_stack(char *str, int word_cnt);
long * words_to_arr(int argc, char **argv);
t_stack	*words_to_stack(int argc, char **argv);


/*   Operations  */

void swap(t_stack **stck, char stck_name);
void double_swap(t_stack **a, t_stack **b);
void push(t_stack **src, t_stack **dest, char dest_name);
void rotate(t_stack **stck, char stck_name);
void double_rotate(t_stack **a, t_stack **b);
void reverse_rotate(t_stack **stck, char stck_name);
void double_reverse_rotate(t_stack **a, t_stack **b);

/*   MIN & MAX   */

t_stack *find_smallest_cont(t_stack * stck);
t_stack *find_largest_cont(t_stack * stck);

/*   SIZE & LEN  */

int stack_size(t_stack **stck);

/*   Print   */

void print_stack_contents(t_stack * stck);
void print_node_content(t_stack * stck);
void print_stack_positions(t_stack * stck);
void print_stack_targets(t_stack * stck);
void print_stack_cost_b(t_stack * stck);
void print_stack_cost_a(t_stack * stck);
void print_stack_cost(t_stack * stck);

/*   Funtions to Order list of THREE elements  */

void order_three_elements(t_stack **stck);
void order_case_one(t_stack **stck);
void order_case_two(t_stack **stck);
void order_case_three(t_stack **stck);
void order_case_four(t_stack **stck);
void order_case_five(t_stack **stck);

/*   Make Stacks  */

t_stack *create_node();
t_stack *array_to_stack(long *array, int array_len);
t_stack	*args_to_stack(int argc, char **argv);
t_stack *create_a(int argc, char **argv);
void push_to_b(t_stack ** a, t_stack **b);


/*      Positions, Targets, Costs       */

int get_target(t_stack ** a, t_stack **b);
void set_positions(t_stack ** stck);
void set_targets(t_stack ** a, t_stack **b);
int calc_cost(t_stack **b, int index);
void set_cost(t_stack **b);
t_stack *find_lowest_cost(t_stack **b);