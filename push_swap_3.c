/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:11:53 by akrid             #+#    #+#             */
/*   Updated: 2024/02/22 21:03:44 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack **a)
{
    t_stack *first;

    first = *a;
    if (first && first->next)
    {
        *a = first->next;
        first->next = (*a)->next;
        (*a)->next = first;
    }
    write(1, "sa\n", 3);
}

void    sb(t_stack **b)
{
    t_stack *first;

    first = *b;
    if (first && first->next)
    {
        *b = first->next;
        first->next = (*b)->next;
        (*b)->next = first;
    }
    write(1, "sb\n", 3);
}

void    ss(t_p_swap *stacks)
{
    sa(&stacks->a);
    sb(&stacks->b);
}

void    pa(t_p_swap *stacks)
{
    t_stack *temp;
    
    if (stacks->b != NULL)
    {
        temp = stacks->b;
        stacks->b = stacks->b->next;
        add_front(&stacks->a, temp);
        write(1, "pa\n", 3);
    }
}

void    pb(t_p_swap *stacks)
{
    t_stack *temp;
    
    if (stacks->a != NULL)
    {
        temp = stacks->a;
        stacks->a = stacks->a->next;
        add_front(&stacks->b, temp);
        write(1, "pb\n", 3);
    }
}