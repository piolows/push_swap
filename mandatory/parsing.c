/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:09:48 by ppolinta          #+#    #+#             */
/*   Updated: 2024/02/25 19:44:11 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checksorted(t_stack *stack)
{
	int	i;

	while (stack)
	{
		i = stack->n;
		stack = stack->next;
		if (stack)
			if (i > stack->n)
				return (0);
	}
	return (1);
}

void	checkall(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] && ((s[i] >= '0' && s[i] <= '9') || s[i] == ' '
				|| s[i] == '+' || s[i] == '-'))
		{
			if (s[i] == '+' || s[i] == '-')
			{
				if ((i != 0 && s[i - 1] != ' ')
					|| !(s[i + 1] >= '0' && s[i + 1] <= '9'))
					end (1, s, NULL, NULL);
			}
			i++;
		}
		else
			end(1, s, NULL, NULL);
	}
}

char	*ps_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	str[ft_strlen(s1)] = ' ';
	ft_strlcpy(str + ft_strlen(s1) + 1, s2, ft_strlen(s2) + 1);
	free(s1);
	return (str);
}

int	checkfornum(char *s)
{
	int	i;
	int	n;

	i = -1;
	n = 0;
	while (s[++i])
		if (ft_isdigit(s[i]))
			n = 1;
	return (n);
}

char	**checkargs(int ac, char **av)
{
	int		i;
	char	*s;
	char	**s_arr;

	if (ac == 1)
		exit(0);
	s = NULL;
	i = 1;
	while (i < ac)
	{
		if (!checkfornum(av[i]))
			end(1, s, NULL, NULL);
		s = ps_strjoin(s, av[i++]);
	}
	checkall(s);
	s_arr = ft_split(s, ' ');
	i = -1;
	while (s_arr[++i])
		if (ft_strlen(s_arr[i]) > 11)
			end(1, s, s_arr, NULL);
	free(s);
	return (s_arr);
}
