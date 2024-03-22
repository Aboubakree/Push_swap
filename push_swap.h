/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:28:17 by akrid             #+#    #+#             */
/*   Updated: 2024/03/22 01:27:51 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_operation
{
	long				element_to_push;
	long				element_to_follow;
	int					index_to_follow;
	int					index_to_push;
	int					total_moves;
	struct s_operation	*next;
}						t_operation;

typedef struct s_stack
{
	long				val;
	struct s_stack		*next;
}						t_stack;

typedef struct s_p_swap
{
	t_stack				*a;
	t_stack				*b;
	int					size_a;
	int					size_b;
}						t_p_swap;

int						length(char **str);
int						ft_lstsize(t_stack *lst);
long					ft_atoi(const char *str, t_stack *a);
void					error(void);
void					clean(char **str);
void					clean_stack(t_stack *x);
void					clean_operation(t_operation *operation);
long					*allocat_array(int size);
t_stack					*node(long data);
void					add_back(t_stack **list, t_stack *node);
void					add_front(t_stack **list, t_stack *node);
t_operation				*new_operation(void);
void					operation_add_back(t_operation **list,
							t_operation *operation);
int						count_words(char *str);
void					fill_tab(long t[], t_stack *x);
int						get_min(long t[], int size);
int						get_max(long t[], int size);
int						valid_digits(int argc, char **list_args, int i);
void					fill_stack(int argc, char **list_args, t_stack **a,
							int i);
void					check_INT(long test, t_stack *a);
void					check_stack(t_stack *a);
void					parse_args(int argc, char **argv, t_stack **a,
							t_p_swap *stacks);
int						check_sorting(t_stack *a);
void					sa(t_stack **a);
void					sb(t_stack **b);
void					ss(t_stack **a, t_stack **b);
void					pa(t_stack **a, t_stack **b, t_p_swap *stack);
void					pb(t_stack **a, t_stack **b, t_p_swap *stack);
void					ra(t_stack **a);
void					rb(t_stack **b);
void					rr(t_stack **a, t_stack **b);
void					rra(t_stack **a);
void					rrb(t_stack **b);
void					rrr(t_stack **a, t_stack **b);
int						check_all_neg_pos(long distance[], int size);
int						get_minimum_distance(long distance[], int size);
int						check_all_neg_pos_b_a(long distance[], int size);
int						get_minimum_distance_b_a(long distance[], int size);
void					get_operation_moves_b_to_a(t_p_swap *stacks,
							t_operation **list_operation);
int						ft_min(int a, int b);
int						ft_abs(int a);
void					get_rest_of_moves(t_p_swap *stacks, t_operation *temp);
void					get_operation_moves_a_to_b(t_p_swap *stacks,
							t_operation **list_operation);
void					rotate_b_a_to_b(t_stack **b, t_p_swap *stacks,
							t_operation *element);
void					rotate_a_b_to_a(t_stack **a, t_p_swap *stacks,
							t_operation *element);
void					rotate_a_a_to_b(t_stack **a, t_p_swap *stacks,
							t_operation *element);
void					rotate_ab_up_a_to_b(t_stack **a, t_stack **b,
							t_p_swap *stacks, t_operation *element);
void					rotate_ab_down_a_to_b(t_stack **a, t_stack **b,
							t_operation *element);
void					rotate_ab_a_to_b(t_stack **a, t_stack **b,
							t_p_swap *stacks, t_operation *element);
void					push_b(t_stack **a, t_stack **b, t_p_swap *stacks,
							t_operation *list_operation);
void					push_a(t_stack **a, t_stack **b, t_p_swap *stacks,
							t_operation *list_operation);
void					ascinding_sort(t_stack **a, t_p_swap *stacks);
void					sort_to_b(t_stack **a, t_stack **b, t_p_swap *stacks);
void					sort_to_a(t_stack **a, t_stack **b, t_p_swap *stacks);
void					get_index_to_follow_in_b(t_p_swap *stacks,
							t_operation **operation);
void					get_index_to_follow_in_a(t_p_swap *stacks,
							t_operation **operation);
void					sort_two(t_stack **a);
void					sort_three(t_stack **a, t_p_swap *stacks);
void					sort_four(t_stack **a, t_stack **b, t_p_swap *stacks);
void					sort_five(t_stack **a, t_stack **b, t_p_swap *stacks);
void					stack_sort(t_stack **a, t_stack **b, t_p_swap *stacks);
void					final_sort(t_stack **a, t_stack **b, t_p_swap *stacks);
void					stack_sort(t_stack **a, t_stack **b, t_p_swap *stacks);
int						main(int argc, char **argv);

#endif