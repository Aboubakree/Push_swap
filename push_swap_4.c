/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:18:22 by akrid             #+#    #+#             */
/*   Updated: 2024/02/24 16:02:23 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_stack **a)
{
    t_stack *temp;
    t_stack *iter;
    
    temp = *a;
    if (temp){
        *a = temp->next;
        temp->next = NULL;
    }
    iter = *a;
    while (iter && iter->next)
        iter = iter->next;
    if (iter){
        iter->next = temp;
        write(1, "ra\n", 3);
    }
    else
        *a = temp;
}

void    rb(t_stack **b)
{
    t_stack *temp;
    t_stack *iter;
    
    temp = *b;
    if (temp){
        *b = temp->next;
        temp->next = NULL;
    }
    iter = *b;
    while (iter && iter->next)
        iter = iter->next;
    if (iter){
        iter->next = temp;
        write(1, "rb\n", 3);
    }
    else
        *b = temp;
}

void    rr(t_p_swap *stacks)
{
    ra(&stacks->a);
    rb(&stacks->b);
}

void    rra(t_stack **a)
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
        write(1, "rra\n", 4);
    }
}

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

void    rrr(t_p_swap *stacks)
{
    rra(&stacks->a);
    rrb(&stacks->b);
}