/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:14:26 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/25 19:44:27 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ps_atol(const char *str)
{
	int			i;
	long long	sign;
	long long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if ((result == 922337203685477580
				&& str[i] > '7') || (result > 922337203685477580))
			return (-1 * (sign != -1));
		result = (result * 10) + (str[i++] - '0');
	}
	return (result * sign);
}

t_stack	*init_stack(char **arr, t_stack *stack)
{
	int			i;
	long long	n;
	t_stack		*new;

	i = 0;
	n = 0;
	while (arr[i])
	{
		n = ps_atol(arr[i]);
		if (n < -2147483648 || n > 2147483647)
			end(1, NULL, arr, NULL);
		new = newnode((int)n);
		node_addback(&stack, new);
		new->i = i;
		i++;
	}
	freearray(arr);
	return (stack);
}
