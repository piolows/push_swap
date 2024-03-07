/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:22:30 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/25 19:09:13 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacksize(t_stack *stack)
{
	int		n;
	t_stack	*temp;

	temp = stack;
	n = 0;
	while (temp)
	{
		temp = temp->next;
		n++;
	}
	return (n);
}

t_stack	*lastnode(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	node_addback(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!*stack)
	{
		*stack = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		temp = lastnode(*stack);
		new->prev = temp;
		temp->next = new;
	}
}

void	node_addfront(t_stack **stack, t_stack *node)
{
	if (!*stack)
	{
		*stack = node;
		node->next = NULL;
		node->prev = NULL;
	}
	else
	{
		(*stack)->prev = node;
		node->next = *stack;
		node->prev = NULL;
		*stack = node;
	}
}

t_stack	*newnode(int num)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->target = NULL;
	node->cost = 0;
	node->cheapest = 0;
	node->r = 0;
	node->i = -1;
	node->n = num;
	return (node);
}
