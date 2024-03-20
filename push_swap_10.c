/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:54:53 by akrid             #+#    #+#             */
/*   Updated: 2024/03/20 17:57:24 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b_a_to_b(t_stack **b, t_p_swap *stacks, t_operation *element)
{
	if (element->index_to_follow > (stacks->size_b / 2)){
		element->index_to_follow = stacks->size_b - element->index_to_follow;
		while(element->index_to_follow){
			rrb(b);
			element->index_to_follow --;
		}
	}
	else {
		while(element->index_to_follow){
			rb(b);
			element->index_to_follow --;
		}
	}
}

void	rotate_a_b_to_a(t_stack **a, t_p_swap *stacks, t_operation *element)
{
	if (element->index_to_follow > (stacks->size_a / 2))
	{
		element->index_to_follow = stacks->size_a - element->index_to_follow;
		while(element->index_to_follow)
		{
			rra(a);
			element->index_to_follow --;
		}
	}
	else 
	{
		while(element->index_to_follow)
		{
			ra(a);
			element->index_to_follow --;
		}
	}
}

void	rotate_a_a_to_b(t_stack **a, t_p_swap *stacks, t_operation *element)
{
	if (element->index_to_push > (stacks->size_a / 2)){
		element->index_to_push = stacks->size_a - element->index_to_push;
		while(element->index_to_push){
			rra(a);
			element->index_to_push --;
		}
	}
	else {
		while(element->index_to_push){
			ra(a);
			element->index_to_push --;
		}
	}
}

void	rotate_ab_up_a_to_b(t_stack **a, t_stack **b, t_p_swap *stacks, t_operation *element)
{
	element->index_to_follow = stacks->size_b - element->index_to_follow;
	element->index_to_push = stacks->size_a - element->index_to_push;
	while (element->index_to_push && element->index_to_follow)
	{
		rrr(a, b);
		element->index_to_push --;
		element->index_to_follow --;
	}
	while(element->index_to_push)
	{
		rra(a);
		element->index_to_push --;
	}
	while(element->index_to_follow)
	{
		rrb(b);
		element->index_to_follow --;
	}
}

void	rotate_ab_down_a_to_b(t_stack **a, t_stack **b, t_operation *element)
{
	while(element->index_to_push && element->index_to_follow)
	{
		rr(a, b);
		element->index_to_push --;
		element->index_to_follow --;
	}
	while(element->index_to_follow)
	{
		rb(b);
		element->index_to_follow --;
	}
	while(element->index_to_push)
	{
		ra(a);
		element->index_to_push --;
	}
}

void	rotate_ab_a_to_b(t_stack **a, t_stack **b, t_p_swap *stacks, t_operation *element)
{
	if (element->index_to_push > (stacks->size_a / 2) && element->index_to_follow > (stacks->size_b / 2))
		rotate_ab_up_a_to_b(a, b, stacks, element);
	else if (element->index_to_push <= (stacks->size_a / 2) && element->index_to_follow <= (stacks->size_b / 2))
		rotate_ab_down_a_to_b(a, b, element);
	else 
	{
		rotate_a_a_to_b(a, stacks, element);
		rotate_b_a_to_b(b, stacks, element);
	}
}