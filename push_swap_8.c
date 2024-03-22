/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:48:32 by akrid             #+#    #+#             */
/*   Updated: 2024/03/22 01:42:29 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->val > (*a)->next->val)
		sa(a);
}

int	check_all_neg_pos(long distance[], int size)
{
	int	i;
	int	dist;

	i = 0;
	dist = 0;
	while (i < size)
	{
		if (distance[i] < distance[dist])
			dist = i;
		i++;
	}
	return (dist);
}

int	get_minimum_distance(long distance[], int size)
{
	int	i;
	int	dist;

	i = 0;
	while (i < size && distance[i] > 0)
		i++;
	if (i == size)
		return (check_all_neg_pos(distance, size));
	i = 0;
	while (i < size && distance[i] < 0)
		i++;
	if (i == size)
		return (check_all_neg_pos(distance, size));
	dist = i;
	while (i < size)
	{
		if (distance[i] > 0 && distance[i] < distance[dist])
			dist = i;
		i++;
	}
	return (dist);
}

int	check_all_neg_pos_b_a(long distance[], int size)
{
	int	i;
	int	dist;

	i = 0;
	dist = 0;
	while (i < size)
	{
		if (distance[i] > distance[dist])
			dist = i;
		i++;
	}
	return (dist);
}

int	get_minimum_distance_b_a(long distance[], int size)
{
	int	i;
	int	dist;

	i = 0;
	while (i < size && distance[i] < 0)
		i++;
	if (i == size)
		return (check_all_neg_pos_b_a(distance, size));
	i = 0;
	while (i < size && distance[i] > 0)
		i++;
	if (i == size)
		return (check_all_neg_pos_b_a(distance, size));
	dist = i;
	while (i < size)
	{
		if (distance[i] < 0 && distance[i] > distance[dist])
			dist = i;
		i++;
	}
	return (dist);
}
