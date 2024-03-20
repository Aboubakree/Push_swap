/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 04:17:12 by akrid             #+#    #+#             */
/*   Updated: 2024/03/20 17:50:58 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack    *node(long data)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (new == NULL)
        return (NULL);
    new->next = NULL;
    new->val = data;
    return (new);
}

void    add_back(t_stack **list, t_stack *node)
{
    t_stack *temp;

    if (list && *list == NULL)
        *list = node;
    else
    {
        temp = *list;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = node;
    }
}

void	add_front(t_stack **list, t_stack *node)
{
	node->next = NULL;
	node->next = *list;
	*list = node;
}
t_operation	*new_operation()
{
	t_operation	*new;

	new = malloc(sizeof(t_operation));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	return (new);
}

void	operation_add_back(t_operation	**list, t_operation *operation)
{
	t_operation *temp;

	if (*list == NULL)
		*list = operation;
	else {
		temp = *list;
		while (temp->next)
			temp = temp->next;
		temp->next = operation;
	}
}