/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 14:49:24 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/26 16:07:10 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move4(int m, int s, t_stack **a, t_stack **b)
{
	if (m == 'R')
	{
		if (s == 'a')
		{
			rrotate(a);
			ft_putendl_fd("rra", 1);
		}
		if (s == 'b')
		{
			rrotate(b);
			ft_putendl_fd("rrb", 1);
		}
		if (s == 'r')
		{
			rrotate(a);
			rrotate(b);
			ft_putendl_fd("rrr", 1);
		}
	}
}

void	move3(int m, int s, t_stack **a, t_stack **b)
{
	if (m == 'r')
	{
		if (s == 'a')
		{
			rotate(a);
			ft_putendl_fd("ra", 1);
		}
		if (s == 'b')
		{
			rotate(b);
			ft_putendl_fd("rb", 1);
		}
		if (s == 'r')
		{
			rotate(a);
			rotate(b);
			ft_putendl_fd("rr", 1);
		}
	}
}

void	move2(int m, int s, t_stack **a, t_stack **b)
{
	if (m == 's')
	{
		if (s == 'a')
		{
			swap(a);
			ft_putendl_fd("sa", 1);
		}
		if (s == 'b')
		{
			swap(b);
			ft_putendl_fd("sb", 1);
		}
		if (s == 's')
		{
			swap(a);
			swap(b);
			ft_putendl_fd("ss", 1);
		}
	}
}

void	move1(int m, int s, t_stack **a, t_stack **b)
{
	if (m == 'p')
	{
		if (s == 'a')
		{
			push(a, b);
			ft_putendl_fd("pa", 1);
		}
		else if (s == 'b')
		{
			push(b, a);
			ft_putendl_fd("pb", 1);
		}
	}
}

void	move(int m, int s, t_stack **a, t_stack **b)
{
	if (m == 'p')
		move1(m, s, a, b);
	else if (m == 's')
		move2(m, s, a, b);
	else if (m == 'r')
		move3(m, s, a, b);
	else if (m == 'R')
		move4(m, s, a, b);
}
