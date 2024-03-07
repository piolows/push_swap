/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:29:09 by ppolinta          #+#    #+#             */
/*   Updated: 2024/03/02 19:32:12 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	execinput2(char *s, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(s, "ra\n", 3))
		rotate(a);
	else if (!ft_strncmp(s, "rb\n", 3))
		rotate(b);
	else if (!ft_strncmp(s, "rr\n", 3))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strncmp(s, "rra\n", 4))
		rrotate(a);
	else if (!ft_strncmp(s, "rrb\n", 4))
		rrotate(b);
	else if (!ft_strncmp(s, "rrr\n", 4))
	{
		rrotate(a);
		rrotate(b);
	}
	else
		return (0);
	return (1);
}

int	execinput(char *s, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(s, "pa\n", 3))
		push(a, b);
	else if (!ft_strncmp(s, "pb\n", 3))
		push(b, a);
	else if (!ft_strncmp(s, "sa\n", 3))
		swap(a);
	else if (!ft_strncmp(s, "sb\n", 3))
		swap(b);
	else if (!ft_strncmp(s, "ss\n", 3))
	{
		swap(a);
		swap(b);
	}
	else
		return (execinput2(s, a, b));
	return (1);
}
