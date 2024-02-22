/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:27:44 by akrid             #+#    #+#             */
/*   Updated: 2024/02/22 21:09:30 by akrid            ###   ########.fr       */
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

void    parse_args(int argc, char **argv, t_stack **a)
{
	char	**temp;

    if (argc == 2)
	{
		temp = ft_split_v2(argv[1], " \t\n");
        if(valid_digits(length(temp), temp, 0)) {
			fill_stack(length(temp) ,temp, a, 0);
			clean(temp);
		}
		else {
			clean(temp);
			error();
		}
	}
	else {
        if(valid_digits(argc, argv, 1))
			fill_stack(argc, argv, a, 1);
		else
			error();
	}
	check_stack(*a);
}


void	stack_sort(t_p_swap *stacks)
{
	stacks->b = NULL;
	sb(&(stacks->a));
}

int main(int argc, char **argv)
{
    t_p_swap    stacks;
	t_stack *x = NULL;
	int		sort;

    parse_args(argc, argv, &stacks.a);
	sort = check_sorting(stacks.a);
	if (sort == 0)
		stack_sort(&stacks);
	x = stacks.a;
	while (x)
	{
		printf("%ld\n", x->val);
		x = x->next;
	}
	if (sort)
		printf("Sorting : OK\n");
	clean_stack(stacks.a);
    return (0);
}
