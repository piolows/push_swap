/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:14:05 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/25 19:43:00 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	end(int x, char *s, char **arr, t_stack *stack)
{
	if (x == 1)
		ft_putendl_fd("Error", 2);
	if (s)
		free (s);
	if (arr)
		freearray(arr);
	if (stack)
		freestack(stack);
	exit(x);
}

void	freearray(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
