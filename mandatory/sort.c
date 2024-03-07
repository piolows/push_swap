/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:07:58 by ppolinta          #+#    #+#             */
/*   Updated: 2024/03/02 19:18:15 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_b(t_stack **a, t_stack **b)
{
	if (findlargest(b) != 0)
	{
		if (findlargest(b) <= stacksize(*b) / 2 && stacksize(*b) > 1)
			while (findlargest(b) != 0)
				move('r', 'b', a, b);
		else if (findlargest(b) > stacksize(*b) / 2 && stacksize(*b) > 1)
			while (findlargest(b) != 0)
				move('R', 'b', a, b);
	}
}

void	order_a(t_stack **a, t_stack **b)
{
	if (!checksorted(*a))
	{
		if (findlargest(a) <= stacksize(*a) / 2)
			while (!checksorted(*a))
				move('r', 'a', a, b);
		else if (findlargest(a) > stacksize(*a) / 2)
			while (!checksorted(*a))
				move('R', 'a', a, b);
	}
}

void	movecheapest(t_stack **a, t_stack **b, int ab)
{
	t_stack	*temp;
	int		ms[2];

	if (ab == 0)
		temp = *a;
	else
		temp = *b;
	while (temp && temp->cheapest != 1)
		temp = temp->next;
	setrotation(temp, ms);
	while (temp->i != 0 && temp->target->i != 0
		&& (temp->r == 1 || temp->r == 2))
		move(ms[0], 'r', a, b);
	if (ab == 0)
		do_rotation1(temp, ms, a, b);
	else
		do_rotation2(temp, ms, a, b);
}

void	sort(t_stack **a, t_stack **b)
{
	move('p', 'b', a, b);
	if (stacksize(*a) > 3)
		move('p', 'b', a, b);
	while (stacksize(*a) > 3)
	{
		settargets_a(a, b);
		movecheapest(a, b, 0);
		move('p', 'b', a, b);
	}
	order_b(a, b);
	sortthree(a, 'a');
	while (stacksize(*b) > 0)
	{
		settargets_b(b, a);
		movecheapest(a, b, 1);
		move('p', 'a', a, b);
	}
	order_a(a, b);
}
