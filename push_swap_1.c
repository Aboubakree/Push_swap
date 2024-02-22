/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:28:27 by akrid             #+#    #+#             */
/*   Updated: 2024/02/22 20:29:55 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	length(char **str)
{
	int i;
	
	i = 0;
	while(str && str[i])
		i ++;
	return (i);
}

void	error()
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
void	clean(char **str)
{
	int i;

	i = 0;
	while(str && str[i])
		free(str[i ++]);
	free(str);
}

void	clean_stack(t_stack *x)
{
	t_stack *y;
	y = x;
	if (x)
		x = x->next;
	while(y)
	{
		free(y);
		y = x;
		if (x)
			x = x->next;
	}	
}