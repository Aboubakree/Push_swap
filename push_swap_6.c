/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:45:08 by akrid             #+#    #+#             */
/*   Updated: 2024/03/22 00:03:39 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *str)
{
	int	i;
	int	count;
	int	b;

	i = 0;
	count = 0;
	b = 1;
	while (str && str[i] == ' ')
		i ++;
	while (str && str[i])
	{
		if (str[i] != ' ' && b)
		{
			count ++;
			b = 0;
		}
		else if (str[i] == ' ' && !b)
			b = 1;
		i ++;
	}
	return (count);
}

void    parse_args(int argc, char **argv, t_stack **a, t_p_swap *stacks)
{
	int		i;
	char	**temp;

	i = 1;
	*a = NULL;
	while (i < argc)
	{
		if (count_words(argv[i]) == 0)
			error();
		temp = ft_split(argv[i], ' ');
		if(valid_digits(length(temp), temp, 0)) {
			fill_stack(length(temp) ,temp, a, 0);
			clean(temp);
		}
		else {
			clean(temp);
			error();
		}
		i ++;
	}
	stacks->size_a = ft_lstsize(*a);
	stacks->b = NULL;
	stacks->size_b = 0;
}

void	fill_tab(long t[],t_stack *x)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = x;
	while(temp){
		t[i] = temp->val;
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