/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:29:33 by ppolinta          #+#    #+#             */
/*   Updated: 2024/03/02 19:30:27 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../mandatory/push_swap.h"

void	getinput(t_stack **a, t_stack **b);
int		execinput(char *s, t_stack **a, t_stack **b);

#endif