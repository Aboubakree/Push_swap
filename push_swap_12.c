/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_12.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:11:07 by akrid             #+#    #+#             */
/*   Updated: 2024/03/21 14:13:49 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rrb(t_stack **b)
{
    t_stack *temp;
    t_stack *iter;

    iter = *b;
    while (iter && iter->next && iter->next->next)
        iter = iter->next;
    if (iter && iter->next){
        temp = iter->next;
        iter->next = NULL;
        temp->next = *b;
        *b = temp;
        write(1, "rrb\n", 4);
    }
}

void    rrr(t_stack **a, t_stack **b)
{
    t_stack *temp;
    t_stack *iter;

    iter = *a;
    while (iter && iter->next && iter->next->next)
        iter = iter->next;
    if (iter && iter->next){
        temp = iter->next;
        iter->next = NULL;
        temp->next = *a;
        *a = temp;
    }
    iter = *b;
    while (iter && iter->next && iter->next->next)
        iter = iter->next;
    if (iter && iter->next){
        temp = iter->next;
        iter->next = NULL;
        temp->next = *b;
        *b = temp;
    }
    write(1, "rrr\n", 4);
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

void	get_index_to_follow_in_b(t_p_swap *stacks, t_operation **operation)
{
	long	b[stacks->size_b];
	long	distance[stacks->size_b];
	int		i;
	int		dist;

	i = 0;
	fill_tab(b, stacks->b);
	while(i < stacks->size_b)
	{
		distance[i] = ((*operation)->element_to_push) - b[i];
		i ++;
	}
	dist = get_minimum_distance(distance, stacks->size_b);
	(*operation)->element_to_follow = b[dist];
	(*operation)->index_to_follow = dist;
}

void	get_index_to_follow_in_a(t_p_swap *stacks, t_operation **operation)
{
	long	a[stacks->size_a];
	long	distance[stacks->size_a];
	int		i;
	int		dist;

	i = 0;
	fill_tab(a, stacks->a);
	while(i < stacks->size_a)
	{
		distance[i] = ((*operation)->element_to_push) - a[i];
		i ++;
	}
	dist = get_minimum_distance_b_a(distance, stacks->size_a);
	(*operation)->element_to_follow = a[dist];
	(*operation)->index_to_follow = dist;
}