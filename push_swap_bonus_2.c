/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:01:45 by akrid             #+#    #+#             */
/*   Updated: 2024/03/22 01:14:01 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*iter;

	temp = *a;
	if (temp)
	{
		*a = temp->next;
		temp->next = NULL;
	}
	iter = *a;
	while (iter && iter->next)
		iter = iter->next;
	if (iter)
	{
		iter->next = temp;
	}
	else
		*a = temp;
}

void	rb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*iter;

	temp = *b;
	if (temp)
	{
		*b = temp->next;
		temp->next = NULL;
	}
	iter = *b;
	while (iter && iter->next)
		iter = iter->next;
	if (iter)
	{
		iter->next = temp;
	}
	else
		*b = temp;
}

void	rr_extended(t_stack **a)
{
	t_stack	*temp;
	t_stack	*iter;

	temp = *a;
	if (temp)
	{
		*a = temp->next;
		temp->next = NULL;
	}
	iter = *a;
	while (iter && iter->next)
		iter = iter->next;
	if (iter)
	{
		iter->next = temp;
	}
	else
		*a = temp;
}

void	rr(t_stack **a, t_stack **b)
{
	rr_extended(a);
	rr_extended(b);
}

void	rra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*iter;

	iter = *a;
	while (iter && iter->next && iter->next->next)
		iter = iter->next;
	if (iter && iter->next)
	{
		temp = iter->next;
		iter->next = NULL;
		temp->next = *a;
		*a = temp;
	}
}
