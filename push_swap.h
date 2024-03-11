/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:28:17 by akrid             #+#    #+#             */
/*   Updated: 2024/03/10 13:57:01 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <limits.h>

typedef struct s_operation{
    long                element_to_push;
    long                element_to_follow;
	int	                index_to_follow;
	int	                index_to_push;
    int                 total_moves;
    struct s_operation  *next;
} t_operation;

typedef struct s_stack{
    long val;
    struct s_stack *next;
}   t_stack;


typedef struct s_p_swap{
    t_stack *a;
    t_stack *b;
	int		size_a;
	int		size_b;
}   t_p_swap;



int	        length(char **str);
int		    ft_lstsize(t_stack *lst);
void	    error();
void	    clean(char **str);
void	    clean_stack(t_stack *x);
t_stack     *node(long data);
void        add_back(t_stack **list, t_stack *node);
void	    add_front(t_stack **list, t_stack *node);
int			valid_digits(int argc, char **list_args, int i);
void		fill_stack(int argc, char **list_args, t_stack **a, int i);
void		check_INT(long test, t_stack *a);
void		check_stack(t_stack *a);
void    	parse_args(int argc, char **argv, t_stack **a);
int			check_sorting(t_stack *a);
void        sa(t_stack **a);
void        sb(t_stack **b);
void    	ss(t_stack **a, t_stack **b);
void        pa(t_stack **a, t_stack **b, t_p_swap *stack);
void        pb(t_stack **a, t_stack **b, t_p_swap *stack);
void    	ra(t_stack **a);
void    	rb(t_stack **b);
void        rr(t_stack **a, t_stack **b);
void    	rra(t_stack **a);
void    	rrb(t_stack **b);
void        rrr(t_stack **a, t_stack **b);
void	    sort_two(t_stack **a);
void	    sort_three(t_stack **a, t_p_swap *stacks);
void	    sort_four(t_stack **a, t_stack **b, t_p_swap *stacks);
void	    stack_sort(t_stack **a, t_stack **b, t_p_swap *stacks);
int			main(int argc, char **argv);

#endif