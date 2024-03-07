/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:22:26 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/27 17:47:51 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*findsmaller(t_stack *stack, int n)
{
	int		num;
	t_stack	*in;
	t_stack	*temp;

	temp = stack;
	num = INT_MIN;
	in = NULL;
	while (temp)
	{
		if (temp->n < n && temp->n >= num)
		{
			num = temp->n;
			in = temp;
		}
		temp = temp->next;
	}
	return (in);
}

t_stack	*findlarger(t_stack *stack, int n)
{
	int		num;
	t_stack	*in;
	t_stack	*temp;

	temp = stack;
	num = INT_MAX;
	in = NULL;
	while (temp)
	{
		if (temp->n > n && temp->n <= num)
		{
			num = temp->n;
			in = temp;
		}
		temp = temp->next;
	}
	return (in);
}

int	findsmallest(t_stack **stack)
{
	int		num;
	int		in;
	t_stack	*temp;

	temp = *stack;
	num = temp->n;
	in = temp->i;
	temp = temp->next;
	while (temp)
	{
		if (temp->n < num)
		{
			num = temp->n;
			in = temp->i;
		}
		temp = temp->next;
	}
	return (in);
}

int	findlargest(t_stack **stack)
{
	int		num;
	int		in;
	t_stack	*temp;

	temp = *stack;
	num = temp->n;
	in = temp->i;
	temp = temp->next;
	while (temp)
	{
		if (temp->n > num)
		{
			num = temp->n;
			in = temp->i;
		}
		temp = temp->next;
	}
	return (in);
}

void	refreshindex(t_stack **stack)
{
	t_stack	*temp;
	int		ind;

	if (!*stack)
		return ;
	ind = 0;
	temp = *stack;
	while (temp)
	{
		temp->i = ind++;
		temp = temp->next;
	}
}
