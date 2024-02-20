/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrid <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:27:23 by akrid             #+#    #+#             */
/*   Updated: 2023/11/29 14:27:32 by akrid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_conversion(const char **c, va_list *args)
{
	char	*str;

	str = (char *) *c;
	if (*str == 'c')
		return (str ++, ft_putchar(va_arg(*args, int)));
	if (*str == 's')
		return (str ++, ft_putstr(va_arg(*args, char *)));
	if (*str == 'p')
		return (str++,
			ft_puthex((unsigned long) va_arg(*args, void *),
				"0123456789abcdef", 'p'));
	if (*str == 'd' || *str == 'i')
		return (str++, ft_putnbr(va_arg(*args, int)));
	if (*str == 'u')
		return (str++, ft_putnbr((unsigned) va_arg(*args, int)));
	if (*str == 'x')
		return (str++,
			ft_puthex((unsigned) va_arg(*args, int), "0123456789abcdef", 'x'));
	if (*str == 'X')
		return (str++,
			ft_puthex((unsigned) va_arg(*args, int), "0123456789ABCDEF", 'X'));
	if (*str == '%')
		return (str++, ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str ++;
			if (!(*str))
				break ;
			count += check_conversion(&str, &args);
		}
		else
			count += ft_putchar(*str);
		str ++;
	}
	va_end(args);
	return (count);
}
