/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 21:23:09 by akrid             #+#    #+#             */
/*   Updated: 2024/03/22 01:13:16 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_bonus(char *rule, t_stack *a, t_stack *b)
{
	free(rule);
	clean_stack(a);
	clean_stack(b);
	error();
}

void	do_rule(char *rule, t_stack **a, t_stack **b, t_p_swap *stacks)
{
	if (ft_strcmp(rule, "sa\n") == 0)
		sa(a);
	else if (ft_strcmp(rule, "sb\n") == 0)
		sb(a);
	else if (ft_strcmp(rule, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(rule, "pa\n") == 0)
		pa(a, b, stacks);
	else if (ft_strcmp(rule, "pb\n") == 0)
		pb(a, b, stacks);
	else if (ft_strcmp(rule, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(rule, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(rule, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(rule, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(rule, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(rule, "rrr\n") == 0)
		rrr(a, b);
	else
		error_bonus(rule, *a, *b);
}

void	get_instructions(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	char	*rule;

	rule = get_next_line(0);
	while (rule)
	{
		do_rule(rule, a, b, stacks);
		free(rule);
		rule = get_next_line(0);
	}
}

void	is_sort(t_p_swap *stacks)
{
	if (check_sorting(stacks->a))
	{
		if (stacks->size_b == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_p_swap	stacks;

	parse_args(argc, argv, &stacks.a, &stacks);
	check_stack(stacks.a);
	if (stacks.size_a)
	{
		get_instructions(&stacks.a, &stacks.b, &stacks);
		is_sort(&stacks);
	}
	clean_stack(stacks.a);
	clean_stack(stacks.b);
	return (0);
}
