/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:27:44 by akrid             #+#    #+#             */
/*   Updated: 2024/03/22 00:04:23 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	sort_to_b(a, b, stacks);
	sort_three(a, stacks);
	sort_to_a(a, b, stacks);
	ascinding_sort(a, stacks);
}

void	stack_sort(t_stack **a, t_stack **b, t_p_swap *stacks)
{
	stacks->b = NULL;
	stacks->size_a = ft_lstsize(stacks->a);
	if (stacks->size_a == 1){
		clean_stack(*a);
		exit(EXIT_SUCCESS);
	}
	stacks->size_b = 0;
	if (stacks->size_a == 2)
		sort_two(a);
	else if (stacks->size_a == 3)
		sort_three(a, stacks);
	else if (stacks->size_a == 4)
		sort_four(a, b, stacks);
	else if (stacks->size_a == 5)
		sort_five(a, b, stacks);
	else {
		pb(a, b, stacks);
		pb(a, b, stacks);
		final_sort(a, b, stacks);
	}
}

int main(int argc, char **argv)
{
    t_p_swap    stacks;
	int		sort;

    parse_args(argc, argv, &stacks.a, &stacks);
	check_stack(stacks.a);
	sort = check_sorting(stacks.a);
	if (sort == 0)
		stack_sort(&stacks.a, &stacks.b, &stacks);
	clean_stack(stacks.a);
    return (0);
}

