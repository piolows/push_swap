/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortthree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:24:13 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/27 17:45:03 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortthree(t_stack **stack, int s)
{
	int		in;

	in = findlargest(stack);
	if (in == 0)
	{
		move('r', s, stack, NULL);
		if (!checksorted(*stack))
			move('s', s, stack, NULL);
	}
	if (in == 1)
	{
		move('R', s, stack, NULL);
		if (!checksorted(*stack))
			move('s', s, stack, NULL);
	}
	if (in == 2 && !checksorted(*stack))
		move('s', s, stack, NULL);
}
