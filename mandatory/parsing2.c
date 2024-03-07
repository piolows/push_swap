/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:27:52 by ppolinta          #+#    #+#             */
/*   Updated: 2024/03/03 17:37:12 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkdups(t_stack *stack)
{
	t_stack	*temp;
	int		num;

	while (stack->next)
	{
		num = stack->n;
		temp = stack->next;
		while (temp)
		{
			if (num == temp->n)
				return (1);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (0);
}
