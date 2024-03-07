/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:43:59 by ppolinta          #+#    #+#             */
/*   Updated: 2023/11/16 16:43:12 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	typecheck(char c, va_list args)
{
	if (c == '%')
		return (write(1, "%%", 1));
	else if (c == 'i' || c == 'd')
		return (pf_putint(va_arg(args, int)));
	else if (c == 's')
		return (pf_putstr(va_arg(args, char *)));
	else if (c == 'c')
		return (pf_putchar(va_arg(args, int)));
	else if (c == 'u')
		return (pf_putuint(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (pf_putmem(va_arg(args, void *)));
	else if (c == 'x')
		return (pf_puthex(va_arg(args, unsigned int), 0));
	else if (c == 'X')
		return (pf_puthex(va_arg(args, unsigned int), 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			count += typecheck(*(format + i++ + 1), args);
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
