/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:46:40 by akrid             #+#    #+#             */
/*   Updated: 2024/03/20 17:47:15 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_p_swap *stacks)
{
	long	t[stacks->size_a];
	int		min;
	int		max;

	fill_tab(t, *a);
	min = get_min(t, stacks->size_a);
	max = get_max(t, stacks->size_a);
	if (max == 0){
		ra(a);
		if (min == 2)
			sa(a);
	}
	else if(max == 1){
		rra(a);
		if (min == 0)
			sa(a);
	}
	else if(max == 2 && min == 1){
		sa(a);
	}
}

void	sort_four(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	long	t[stacks->size_a];
	int		min;
	
	fill_tab(t, *a);
	min = get_min(t, stacks->size_a);
	if (min == 0)
		pb(a, b, stacks);
	else if (min == 1){
		sa(a);
		pb(a, b, stacks);
	}
	else if (min == 2){
		rra(a);
		rra(a);
		pb(a, b, stacks);
	}
	else if (min == 3){
		rra(a);
		pb(a, b, stacks);
	}
	sort_three(a, stacks);
	pa(a, b, stacks);
}

void	sort_five_extand(t_stack **a, t_stack **b, t_p_swap *stacks, int min)
{
	if (min == 3){
		rra(a);
		rra(a);
		pb(a, b, stacks);
	}
	else if (min == 4){
		rra(a);
		pb(a, b, stacks);
	}	
}

void	sort_five(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	long	t[stacks->size_a];
	int		min;
	
	fill_tab(t, *a);
	min = get_min(t, stacks->size_a);
	if (min == 0)
		pb(a, b, stacks);
	else if (min == 1){
		sa(a);
		pb(a, b, stacks);
	}
	else if (min == 2){
		ra(a);
		ra(a);
		pb(a, b, stacks);
	}
	else
		sort_five_extand(a, b, stacks, min);
	sort_four(a, b, stacks);
	pa(a, b, stacks);
}

void	sort_two(t_stack **a)
{
	if ((*a)->val > (*a)->next->val)
		sa(a);
}