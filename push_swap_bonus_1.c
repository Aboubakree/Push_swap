/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:00:47 by akrid             #+#    #+#             */
/*   Updated: 2024/03/22 01:37:36 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*first;

	first = *a;
	if (first && first->next)
	{
		*a = first->next;
		first->next = (*a)->next;
		(*a)->next = first;
	}
}

void	sb(t_stack **b)
{
	t_stack	*first;

	first = *b;
	if (first && first->next)
	{
		*b = first->next;
		first->next = (*b)->next;
		(*b)->next = first;
	}
}

void	ss(t_stack **a, t_stack **b)
{
	t_stack	*first;

	first = *a;
	if (first && first->next)
	{
		*a = first->next;
		first->next = (*a)->next;
		(*a)->next = first;
	}
	first = *b;
	if (first && first->next)
	{
		*b = first->next;
		first->next = (*b)->next;
		(*b)->next = first;
	}
}

void	pa(t_stack **a, t_stack **b, t_p_swap *stack)
{
	t_stack	*temp;

	if (*b != NULL)
	{
		temp = *b;
		(*b) = (*b)->next;
		add_front(a, temp);
		stack->size_a++;
		stack->size_b--;
	}
}

void	pb(t_stack **a, t_stack **b, t_p_swap *stack)
{
	t_stack	*temp;

	if (*a != NULL)
	{
		temp = *a;
		*a = (*a)->next;
		add_front(b, temp);
		stack->size_a--;
		stack->size_b++;
	}
}
