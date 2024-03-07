/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getinput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:29:09 by ppolinta          #+#    #+#             */
/*   Updated: 2024/03/02 19:32:12 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	getinput(t_stack **a, t_stack **b)
{
	char	*str;

	str = NULL;
	while (1)
	{
		str = get_next_line(0);
		if (str)
		{
			if (execinput(str, a, b) == 0)
			{
				free(str);
				freestack(*a);
				freestack(*b);
				end(1, NULL, NULL, NULL);
			}
			free(str);
		}
		if (!str)
			break ;
	}
}
