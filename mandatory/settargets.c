/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settargets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:10:08 by ppolinta          #+#    #+#             */
/*   Updated: 2024/03/02 18:10:14 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*findtarget_b(t_stack *b, t_stack **a)
{
	t_stack	*temp;
	int		t;

	temp = findlarger(*a, b->n);
	if (!temp)
	{
		t = findsmallest(a);
		temp = *a;
		while (temp && temp->i != t)
			temp = temp->next;
	}
	return (temp);
}

void	settargets_b(t_stack **b, t_stack **a)
{
	t_stack	*temp;

	temp = *b;
	while (temp)
	{
		temp->target = findtarget_b(temp, a);
		setcost(temp, b, a);
		temp = temp->next;
	}
	setcheapest(b);
}

t_stack	*findtarget_a(t_stack *a, t_stack **b)
{
	t_stack	*temp;
	int		t;

	temp = findsmaller(*b, a->n);
	if (!temp)
	{
		t = findlargest(b);
		temp = *b;
		while (temp && temp->i != t)
			temp = temp->next;
	}
	return (temp);
}

void	settargets_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		temp->target = findtarget_a(temp, b);
		setcost(temp, a, b);
		temp = temp->next;
	}
	setcheapest(a);
}
