/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:45:05 by akrid             #+#    #+#             */
/*   Updated: 2023/12/02 15:45:15 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, char *base, char converge)
{
	int		count;

	count = 0;
	if (converge == 'p')
		count += ft_putstr("0x");
	if (n > 15)
	{
		count += ft_puthex(n / 16, base, 'x');
		count += ft_puthex(n % 16, base, 'x');
	}
	else
		count += ft_putchar(base[n]);
	return (count);
}
