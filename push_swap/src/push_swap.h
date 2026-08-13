/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stitovsk <stitovsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:22:05 by stitovsk          #+#    #+#             */
/*   Updated: 2024/04/08 18:34:22 by stitovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MIN -2147483648
#define MAX 2147483647

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*   Stack structure  */

typedef struct structure_stack
{
	long					content;
	int						target;
	int						position;
	int						cost_a;
	int						cost_b;
	int						cost;
	struct structure_stack	*next;

}							t_stack;

/*   Error and Free  */

int							ft_error(void);
void						free_stack(t_stack **head);

/*      NUMBERS     */

int							ft_abs(int num);
long						ft_atol(char *str);
long						stack_contents_mean(t_stack **stck);

/*   Valid input check  */

int							is_digit(int c);
int							is_space(int c);
int							end_or_space(int c);
int							plus_or_minus(int c);
int							is_not_valid(int c);
int							is_alpha(int c);
int							longs_unique(long *arr, int len);
int							input_valid(char *str, int i);
t_stack						*str_to_stack(char *str, int word_cnt, int i,
								int j);
long						*words_to_arr(int argc, char **argv);
t_stack						*words_to_stack(int argc, char **argv);

/*   Movements  */
void						swap(t_stack **stck, char stck_name);
void						double_swap(t_stack **a, t_stack **b);
void						push(t_stack **src, t_stack **dest, char dest_name);
void						rotate(t_stack **stck, char stck_name);
void						double_rotate(t_stack **a, t_stack **b);
void						reverse_rotate(t_stack **stck, char stck_name);
void						double_reverse_rotate(t_stack **a, t_stack **b);

/*   MIN & MAX   */
int							find_largest_cont_pos(t_stack **stck_stck);
int							find_smallest_cont_pos(t_stack **stck_stck);
int							min_node_is_superior(t_stack **stck_a);

/*   SIZE & LEN  */

int							stack_size(t_stack **stck);
int							word_count(char *str);

/*   Funtions to sort list of THREE elements  */

void						sort_three_elements(t_stack **stck);
void						sort_case_one(t_stack **stck);
void						sort_case_two(t_stack **stck);
void						sort_case_three(t_stack **stck);
void						sort_case_four(t_stack **stck);
void						sort_case_five(t_stack **stck);
void						sort_stacks(t_stack **stck_a, t_stack **stck_b,
								int stck_a_size);

/*   Make Stacks  */

t_stack						*create_node(void);
t_stack						*array_to_stack(long *array, int array_len);
t_stack						*args_to_stack(int argc, char **argv);
t_stack						*create_a(int argc, char **argv);
void						divide_stacks(t_stack **a, t_stack **b,
								int stck_a_size);

/*      Positions, Targets, Costs       */

void						set_positions(t_stack **stck);
void						set_targets(t_stack **a, t_stack **b, long larger);
int							calc_cost(t_stack **b, int index);
void						set_costs(t_stack **stck_a, t_stack **stck_b);
t_stack						*find_lowest_cost(t_stack **b);

/*      SORTING ALGORHITHMS     */

int							first_is_smallest(t_stack **stck_a);
int							is_sorted(t_stack **stck);
void						push_smaller(t_stack **stck_a, t_stack **stck_b,
								long mean);
void						sorting_alg(t_stack **stck_a, t_stack **stck_b,
								t_stack *current_stck);
