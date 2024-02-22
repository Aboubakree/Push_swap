/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:02:19 by akrid             #+#    #+#             */
/*   Updated: 2024/02/22 20:30:13 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    valid_digits(int argc, char **list_args, int i)
{
	int	j;
	int	checker;

	checker = 1;
    while(i < argc && checker)
	{
		j = 0;
		if (list_args[i][j] == '-' && list_args[i][j + 1])
			j ++;
		while(list_args[i] && list_args[i][j])
		{
			if (list_args[i][j] < '0' || list_args[i][j] > '9')
				checker = 0;
			j ++;
		}
		i ++;
	}
	return (checker);
}

void	fill_stack(int argc, char **list_args, t_stack **a, int i)
{
	*a = NULL;
	while (i < argc)
		add_back(a, node(ft_atoi(list_args[i ++])));
}

void	check_INT(long test, t_stack *a)
{
	if (test > 2147483647 || test < -2147483648)
	{
		clean_stack(a);
		error();
		exit(EXIT_FAILURE);
	}
}

void	check_stack(t_stack *a)
{
	long	test;
	t_stack	*temp;
	t_stack	*temp2;

	temp  = a;
	if (temp)
		check_INT(temp->val, a);
	while(temp && temp->next)
	{
		test = temp->val;
		temp2 = temp->next;
		check_INT(test, a);
		while(temp2)
		{
			if (test == temp2->val)
			{
				clean_stack(a);
				error();
				exit(EXIT_FAILURE);
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

int	check_sorting(t_stack *a)
{
	t_stack *temp;

	temp = a;
	while(temp && temp->next)
	{
		if (temp->val > temp->next->val)
			return (0);
		temp = temp->next;
	}
	return (1);
}