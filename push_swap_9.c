/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_9.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:52:33 by akrid             #+#    #+#             */
/*   Updated: 2024/03/20 17:53:53 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_operation_moves_b_to_a(t_p_swap *stacks, t_operation **list_operation)
{
	t_operation *temp;
	int	a_medium;
	int	b_medium;

	a_medium = stacks->size_a / 2;
	b_medium = stacks->size_b / 2;
	temp = *list_operation;
	while(temp){
		temp->total_moves = 0;
		if (temp->index_to_push <= b_medium)
			temp->total_moves += temp->index_to_push;
		else
			temp->total_moves += stacks->size_b - temp->index_to_push;
		if (temp->index_to_follow <= a_medium)
			temp->total_moves += temp->index_to_follow;
		else
			temp->total_moves += stacks->size_a - temp->index_to_follow;
		temp = temp->next;
	}
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	ft_abs(int a)
{
	if (a >= 0)
		return (a);
	return (-a);
}

void	get_rest_of_moves(t_p_swap *stacks, t_operation *temp)
{
	if (temp->index_to_push <= (stacks->size_a / 2))
		temp->total_moves += temp->index_to_push;
	else
		temp->total_moves += stacks->size_a - temp->index_to_push;
	if (temp->index_to_follow <=  (stacks->size_b / 2))
		temp->total_moves += temp->index_to_follow;
	else
		temp->total_moves += stacks->size_b - temp->index_to_follow;
	
}

void	get_operation_moves_a_to_b(t_p_swap *stacks, t_operation **list_operation)
{
	t_operation *temp;

	temp = *list_operation;
	while(temp)
	{
		temp->total_moves = 0;
		if (temp->index_to_push <= (stacks->size_a / 2) 
		&& temp->index_to_follow <=  (stacks->size_b / 2))
			temp->total_moves = ft_min(temp->index_to_push, temp->index_to_follow) 
			+ ft_abs(temp->index_to_push - temp->index_to_follow);
		else if (temp->index_to_push >= (stacks->size_a / 2) 
		&& temp->index_to_follow >=  (stacks->size_b / 2))
			temp->total_moves = ft_min((stacks->size_a - temp->index_to_push),
			(stacks->size_b - temp->index_to_follow)) 
			+ ft_abs((stacks->size_a - temp->index_to_push) 
			- (stacks->size_b - temp->index_to_follow));
		else
			get_rest_of_moves(stacks, temp);
		temp = temp->next;
	}
}