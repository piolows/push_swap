/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:13:42 by ppolinta          #+#    #+#             */
/*   Updated: 2023/11/16 14:37:42 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		pf_putchar(char c);
int		pf_putint(int n);
int		pf_putuint(unsigned int n);
int		pf_putstr(char *s);
int		pf_putmem(void *mem);
int		pf_puthex(unsigned long n, int cs);

#endif