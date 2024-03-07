/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:42:44 by ppolinta          #+#    #+#             */
/*   Updated: 2023/11/16 14:14:10 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putuint(unsigned int n)
{
	int		count;

	count = 0;
	if (n > 9)
		count += pf_putuint(n / 10);
	count += pf_putchar((n % 10) + '0');
	return (count);
}
