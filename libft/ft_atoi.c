/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <akrid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:25:53 by akrid             #+#    #+#             */
/*   Updated: 2024/03/20 16:17:04 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_INT(long test, t_stack *a)
{
	if (test > 2147483647 || test < -2147483648)
	{
		clean_stack(a);
		error();
		exit(EXIT_FAILURE);
	}
}

long	ft_atoi(const char *str, t_stack *a)
{
	long	ng;
	long	res;

	ng = 1;
	res = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str ++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			ng = -ng;
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res += *str - '0';
		str ++;
		check_INT(res * ng, a);
	}
	return (res * ng);
}
