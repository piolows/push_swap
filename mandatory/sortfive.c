/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 20:32:40 by ppolinta          #+#    #+#             */
/*   Updated: 2024/03/04 20:42:55 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	movesmallest(t_stack **a, t_stack **b)
{
	if (findsmallest(a) != 0)
	{
		if (findsmallest(a) <= stacksize(*a) / 2 && stacksize(*a) > 1)
			while (findsmallest(a) != 0)
				move('r', 'a', a, b);
		else if (findsmallest(a) > stacksize(*a) / 2 && stacksize(*a) > 1)
			while (findsmallest(a) != 0)
				move('R', 'a', a, b);
	}
}

void	sortfive(t_stack **a, t_stack **b)
{
	while (stacksize(*a) > 3)
	{
		movesmallest(a, b);
		move('p', 'b', a, b);
	}
	sortthree(a, 'a');
	while (stacksize(*b) > 0)
		move('p', 'a', a, b);
}
