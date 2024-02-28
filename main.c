/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:27:44 by akrid             #+#    #+#             */
/*   Updated: 2024/02/27 16:11:03 by akrid            ###   ########.fr       */
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
		temp = ft_split_v2(argv[1], " \t\n\r\v\f");
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

void	fill_tab(long t[],t_stack *x)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = x;
	while(temp){
		t[i] = temp->val;
		// printf("t[%d] = %ld\n", i, t[i]);
		temp = temp->next;
		i ++;
	}
}

int	get_min(long t[], int size)
{
	int i;
	int min;

	i = 1;
	min = 0;
	while (i < size){
		if (t[min] > t[i])
			min = i;
		i ++;
	}
	return (min);
}

int	get_max(long t[], int size)
{
	int i;
	int max;

	i = 1;
	max = 0;
	while (i < size){
		if (t[max] < t[i])
			max = i;
		i ++;
	}
	return (max);
}

void	sort_tree(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	long	t[stacks->size_a];
	int		min;
	int		max;

	(void)b;
	fill_tab(t, *a);
	min = get_min(t, stacks->size_a);
	max = get_max(t, stacks->size_a);
	// printf("min : %d --> %ld\n", min, t[min]);
	// printf("max : %d --> %ld\n", max, t[max]);
	if (max == 0){
		ra(&stacks->a);
		if (min == 2)
			sa(&stacks->a);
	}
	else if(max == 1){
		rra(&stacks->a);
		if (min == 0)
			sa(&stacks->a);
	}
	else if(max == 2){
		sa(&stacks->a);
	}
}

void	sort_four(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	long	t[stacks->size_a];
	int		min;
	
	fill_tab(t, *a);
	min = get_min(t, stacks->size_a);
	if (min == 0)
		pb(a, b, stacks);
	else if (min == 1){
		sa(&stacks->a);
		pb(a, b, stacks);
	}
	else if (min == 2){
		rra(&stacks->a);
		rra(&stacks->a);
		pb(a, b, stacks);
	}
	else if (min == 3){
		rra(&stacks->a);
		pb(a, b, stacks);
	}
	sort_tree(a, b, stacks);
	pa(a, b, stacks);
}

void	stack_sort(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	stacks->b = NULL;
	stacks->size_a = ft_lstsize(stacks->a);
	stacks->size_b = 0;
	if (stacks->size_a == 3)
		sort_tree(a, b, stacks);
	else if (stacks->size_a == 4)
		sort_four(a, b, stacks);
	// else if (stacks->size_a == 5)
	// 	sort_five();
	// else
	// 	final_sort();
}

int main(int argc, char **argv)
{
    t_p_swap    stacks;
	t_stack *x = NULL;
	int		sort;

    parse_args(argc, argv, &stacks.a);
	sort = check_sorting(stacks.a);
	if (sort == 0)
		stack_sort(&stacks.a, &stacks.b, &stacks);
	// --------------------------------
	x = stacks.a;
	while (x)
	{
		printf(" %ld ", x->val);
		x = x->next;
	}
	clean_stack(stacks.a);
	// ---------------------------------
	x = stacks.b;
	while (x)
	{
		printf("b : %ld\n", x->val);
		x = x->next;
	}
	clean_stack(stacks.b);
    return (0);
}
