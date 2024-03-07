/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setcost.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 18:08:17 by ppolinta          #+#    #+#             */
/*   Updated: 2024/03/02 18:08:17 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setcheapest(t_stack **stack)
{
	t_stack	*temp;
	int		t;
	int		i;

	temp = *stack;
	t = INT_MAX;
	i = 0;
	while (temp)
	{
		if (temp->cost <= t)
		{
			t = temp->cost;
			i = temp->i;
		}
		if (t == 0)
			break ;
		temp = temp->next;
	}
	temp = *stack;
	while (temp->i != i && temp)
		temp = temp->next;
	temp->cheapest = 1;
}

void	setcost2(t_stack *node, t_stack **stack1, t_stack **stack2)
{
	if (node->i > stacksize(*stack1) / 2
		&& node->target->i <= stacksize(*stack2) / 2)
	{
		node->cost = (stacksize(*stack1) - node->i) + node->target->i;
		node->r = 3;
	}
	else if (node->i <= stacksize(*stack1) / 2
		&& node->target->i > stacksize(*stack2) / 2)
	{
		node->cost = node->i + (stacksize(*stack2) - node->target->i);
		node->r = 4;
	}
}

void	setcost(t_stack *node, t_stack **stack1, t_stack **stack2)
{
	if (node->i <= stacksize(*stack1) / 2
		&& node->target->i <= stacksize(*stack2) / 2)
	{
		if (node->i <= node->target->i)
			node->cost = node->target->i;
		else if (node->i > node->target->i)
			node->cost = node->i;
		node->r = 1;
	}
	else if (node->i > stacksize(*stack1) / 2
		&& node->target->i > stacksize(*stack2) / 2)
	{
		if (stacksize(*stack1) - node->i
			<= stacksize(*stack2) - node->target->i)
			node->cost = stacksize(*stack2) - node->target->i;
		else if (stacksize(*stack1) - node->i
			> stacksize(*stack2) - node->target->i)
			node->cost = stacksize(*stack1) - node->i;
		node->r = 2;
	}
	else
		setcost2(node, stack1, stack2);
}
