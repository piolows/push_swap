/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:08:01 by ppolinta          #+#    #+#             */
/*   Updated: 2024/03/04 20:43:19 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	printstack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	if (!stack)
		printf("Empty stack\n");
	while (temp)
	{
		printf("%d: %d\n", temp->i, temp->n);
		temp = temp->next;
	}
	if (checksorted(stack) && stack)
		printf("Sorted!\n");
	printf("\n");
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
	if (!checksorted(a))
	{
		if (stacksize(a) == 2)
			move('s', 'a', &a, NULL);
		else if (stacksize(a) == 3)
			sortthree(&a, 'a');
		else if (stacksize(a) <= 5)
			sortfive(&a, &b);
		else
			sort(&a, &b);
	}
	freestack(a);
	freestack(b);
	return (0);
}
