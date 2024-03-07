/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:43:52 by ppolinta          #+#    #+#             */
/*   Updated: 2023/11/16 16:50:41 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_puthex(unsigned long n, int cs)
{
	int		x;
	char	*base;

	x = 0;
	if (!cs)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n > 15)
		x += pf_puthex(n / 16, cs);
	x += pf_putchar(base[n % 16]);
	return (x);
}
