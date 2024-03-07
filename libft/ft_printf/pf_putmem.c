/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:44:24 by ppolinta          #+#    #+#             */
/*   Updated: 2023/11/15 19:01:02 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putmem(void *mem)
{
	long	n;
	int		count;

	count = 0;
	n = (unsigned long)mem;
	count += pf_putstr("0x");
	count += pf_puthex(n, 0);
	return (count);
}
