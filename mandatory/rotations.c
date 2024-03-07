/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:15:36 by ppolinta          #+#    #+#             */
/*   Updated: 2024/03/02 19:15:50 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotation2(t_stack *temp, int *ms, t_stack **a, t_stack **b)
{
	while (temp->i != 0)
		move(ms[0], 'b', a, b);
	while (temp->target->i != 0)
		move(ms[1], 'a', a, b);
}

void	do_rotation1(t_stack *temp, int *ms, t_stack **a, t_stack **b)
{
	while (temp->i != 0)
		move(ms[0], 'a', a, b);
	while (temp->target->i != 0)
		move(ms[1], 'b', a, b);
}

void	setrotation(t_stack *temp, int *ms)
{
	if (temp->r == 1)
	{
		ms[0] = 'r';
		ms[1] = 'r';
	}
	else if (temp->r == 2)
	{
		ms[0] = 'R';
		ms[1] = 'R';
	}
	else if (temp->r == 3)
	{
		ms[0] = 'R';
		ms[1] = 'r';
	}
	else if (temp->r == 4)
	{
		ms[0] = 'r';
		ms[1] = 'R';
	}
}
