/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:29:09 by ppolinta          #+#    #+#             */
/*   Updated: 2024/03/02 19:32:12 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	freestack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**s_arr;

	s_arr = checkargs(ac, av);
	a = NULL;
	b = NULL;
	a = init_stack(s_arr, a);
	if (checkdups(a))
		end(1, NULL, NULL, a);
	getinput(&a, &b);
	if (checksorted(a) && !b)
		ft_putendl_fd("OK", 1);
	if (!checksorted(a) || b)
		ft_putendl_fd("KO", 1);
	freestack(a);
	freestack(b);
	return (0);
}
