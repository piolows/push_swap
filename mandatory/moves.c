/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:41:53 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/24 17:51:43 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **take, t_stack **give)
{
	t_stack	*temp;

	if (!*give)
		return ;
	temp = pop(give);
	node_addfront(take, temp);
	refreshindex(take);
	refreshindex(give);
}

void	rrotate(t_stack **stack)
{
	t_stack	*temp1;
	t_stack	*temp2;
	t_stack	*temp3;

	if (!*stack || !(*stack)->next)
		return ;
	temp1 = lastnode(*stack);
	temp2 = *stack;
	temp3 = temp1->prev;
	*stack = temp1;
	temp1->next = temp2;
	temp1->prev = NULL;
	temp2->prev = temp1;
	temp3->next = NULL;
	refreshindex(stack);
}

void	rotate(t_stack **stack)
{
	t_stack	*temp1;
	t_stack	*temp2;

	if (!*stack || !(*stack)->next)
		return ;
	temp1 = pop(stack);
	temp2 = lastnode(*stack);
	temp2->next = temp1;
	temp1->prev = temp2;
	temp1->next = NULL;
	refreshindex(stack);
}

void	swap(t_stack **stack)
{
	t_stack	*temp1;
	t_stack	*temp2;
	t_stack	*temp3;

	if (!*stack || !(*stack)->next)
		return ;
	temp1 = pop(stack);
	temp2 = *stack;
	temp3 = (*stack)->next;
	temp1->prev = temp2;
	temp1->next = temp2->next;
	temp2->next = temp1;
	temp2->prev = NULL;
	if (temp3)
		temp3->prev = temp1;
	refreshindex(stack);
}

t_stack	*pop(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack)
		return (NULL);
	if (!(*stack)->next)
	{
		temp = *stack;
		*stack = NULL;
		return (temp);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	temp->next = NULL;
	refreshindex(stack);
	return (temp);
}
