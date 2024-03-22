/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_11.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:58:31 by akrid             #+#    #+#             */
/*   Updated: 2024/03/22 01:26:14 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack **a, t_stack **b, t_p_swap *stacks,
		t_operation *list_operation)
{
	t_operation	*temp;
	t_operation	*minimum_moves;

	temp = list_operation;
	minimum_moves = list_operation;
	while (temp)
	{
		if (temp->total_moves < minimum_moves->total_moves)
			minimum_moves = temp;
		temp = temp->next;
	}
	rotate_ab_a_to_b(a, b, stacks, minimum_moves);
	pb(a, b, stacks);
}

void	push_a(t_stack **a, t_stack **b, t_p_swap *stacks,
		t_operation *list_operation)
{
	rotate_a_b_to_a(a, stacks, list_operation);
	pa(a, b, stacks);
}

void	ascinding_sort(t_stack **a, t_p_swap *stacks)
{
	long	*t;
	int		min;

	t = allocat_array(stacks->size_a);
	fill_tab(t, *a);
	min = get_min(t, stacks->size_a);
	if (min > (stacks->size_a / 2))
	{
		min = stacks->size_a - min;
		while (min)
		{
			rra(a);
			min--;
		}
	}
	else
	{
		while (min)
		{
			ra(a);
			min--;
		}
	}
	free(t);
}

void	sort_to_b(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	t_operation	*operation;
	t_operation	*list_operation;
	int			i;
	t_stack		*temp;

	while (stacks->size_a > 3)
	{
		i = 0;
		temp = *a;
		list_operation = NULL;
		while (temp)
		{
			operation = new_operation();
			operation->index_to_push = i;
			operation->element_to_push = temp->val;
			get_index_to_follow_in_b(stacks, &operation);
			operation_add_back(&list_operation, operation);
			i++;
			temp = temp->next;
		}
		get_operation_moves_a_to_b(stacks, &list_operation);
		push_b(a, b, stacks, list_operation);
		clean_operation(list_operation);
	}
}

void	sort_to_a(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	t_operation	*operation;

	while (stacks->size_b > 0)
	{
		operation = new_operation();
		operation->index_to_push = 0;
		operation->element_to_push = (*b)->val;
		get_index_to_follow_in_a(stacks, &operation);
		push_a(a, b, stacks, operation);
		clean_operation(operation);
	}
}
