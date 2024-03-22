/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:46:40 by akrid             #+#    #+#             */
/*   Updated: 2024/03/22 01:46:46 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_p_swap *stacks)
{
	long	*t;
	int		min;
	int		max;

	t = allocat_array(stacks->size_a);
	fill_tab(t, *a);
	min = get_min(t, stacks->size_a);
	max = get_max(t, stacks->size_a);
	if (max == 0)
	{
		ra(a);
		if (min == 2)
			sa(a);
	}
	else if (max == 1)
	{
		rra(a);
		if (min == 0)
			sa(a);
	}
	else if (max == 2 && min == 1)
		sa(a);
	free(t);
}

void	sort_four_extand(t_stack **a, t_stack **b, t_p_swap *stacks, int min)
{
	if (min == 2)
	{
		rra(a);
		rra(a);
		pb(a, b, stacks);
	}
	else if (min == 3)
	{
		rra(a);
		pb(a, b, stacks);
	}
}

void	sort_four(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	long	*t;
	int		min;

	t = allocat_array(stacks->size_a);
	fill_tab(t, *a);
	min = get_min(t, stacks->size_a);
	if (min == 0)
		pb(a, b, stacks);
	else if (min == 1)
	{
		sa(a);
		pb(a, b, stacks);
	}
	else
		sort_four_extand(a, b, stacks, min);
	sort_three(a, stacks);
	pa(a, b, stacks);
	free(t);
}

void	sort_five_extand(t_stack **a, t_stack **b, t_p_swap *stacks, int min)
{
	if (min == 2)
	{
		ra(a);
		ra(a);
		pb(a, b, stacks);
	}
	else if (min == 3)
	{
		rra(a);
		rra(a);
		pb(a, b, stacks);
	}
	else if (min == 4)
	{
		rra(a);
		pb(a, b, stacks);
	}
}

void	sort_five(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	long	*t;
	int		min;

	t = allocat_array(stacks->size_a);
	fill_tab(t, *a);
	min = get_min(t, stacks->size_a);
	if (min == 0)
		pb(a, b, stacks);
	else if (min == 1)
	{
		sa(a);
		pb(a, b, stacks);
	}
	else
		sort_five_extand(a, b, stacks, min);
	sort_four(a, b, stacks);
	pa(a, b, stacks);
	free(t);
}
