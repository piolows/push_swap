/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:08:42 by ppolinta          #+#    #+#             */
/*   Updated: 2024/03/04 20:36:00 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				n;
	int				i;
	int				cost;
	int				cheapest;
	int				r;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}	t_stack;

char	**checkargs(int ac, char **av);
void	freearray(char **arr);
void	end(int x, char *s, char **arr, t_stack *stack);
void	freestack(t_stack *stack);
t_stack	*init_stack(char **arr, t_stack *stack);
t_stack	*newnode(int num);
void	node_addfront(t_stack **stack, t_stack *node);
void	node_addback(t_stack **stack, t_stack *new);
t_stack	*lastnode(t_stack *stack);
int		stacksize(t_stack *stack);
int		checksorted(t_stack *stack);
int		checkdups(t_stack *stack);
void	refreshindex(t_stack **stack);
t_stack	*pop(t_stack **stack);
void	swap(t_stack **stack);
void	printstack(t_stack *stack);
void	rotate(t_stack **stack);
void	rrotate(t_stack **stack);
void	push(t_stack **take, t_stack **give);
void	move(int m, int s, t_stack **a, t_stack **b);
void	sortthree(t_stack **stack, int s);
void	sort(t_stack **a, t_stack **b);
int		findlargest(t_stack **stack);
int		findsmallest(t_stack **stack);
t_stack	*findlarger(t_stack *stack, int n);
t_stack	*findsmaller(t_stack *stack, int n);
void	setcost(t_stack *node, t_stack **stack1, t_stack **stack2);
void	setcheapest(t_stack **stack);
void	settargets_a(t_stack **a, t_stack **b);
void	settargets_b(t_stack **b, t_stack **a);
void	setrotation(t_stack *temp, int *ms);
void	do_rotation1(t_stack *temp, int *ms, t_stack **a, t_stack **b);
void	do_rotation2(t_stack *temp, int *ms, t_stack **a, t_stack **b);
void	order_a(t_stack **a, t_stack **b);
void	sortfive(t_stack **a, t_stack **b);

#endif