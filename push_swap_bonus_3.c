/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:03:30 by akrid             #+#    #+#             */
/*   Updated: 2024/03/21 14:05:01 by akrid            ###   ########.fr       */
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
    }
}

void    rrr(t_stack **a, t_stack **b)
{
    t_stack *temp;
    t_stack *iter;

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
    iter = *b;
    while (iter && iter->next && iter->next->next)
        iter = iter->next;
    if (iter && iter->next)
    {
        temp = iter->next;
        iter->next = NULL;
        temp->next = *b;
        *b = temp;
    }
}
