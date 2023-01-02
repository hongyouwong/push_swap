/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:33:33 by hwong             #+#    #+#             */
/*   Updated: 2023/01/02 14:23:47 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Calculates the cost of moving each element of stack B into the correct
*	position in stack A.
*	Two costs are calculated:
*		cost_b represents the cost of getting the element to the top of the B stack
*		cost_a represents the cost of getting to the right position in stack A.
*	If the element is in the bottom half of the stack, the cost will be negative,
*	if it is in the top half, the cost is positive. 
*/
void	get_cost(t_stk **stk_a, t_stk **stk_b)
{
	t_stk	*tmp_a;
	t_stk	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stk_a;
	tmp_b = *stk_b;
	size_a = get_stk_size(tmp_a);
	size_b = get_stk_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

/*
*	Finds the element in stack B with the cheapest cost to move to stack A
*	and moves it to the correct position in stack A.
*/
void	do_cheapest_move(t_stk **stk_a, t_stk **stk_b)
{
	t_stk	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stk_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (nb_abs(tmp->cost_a) + nb_abs(tmp->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(tmp->cost_b) + nb_abs(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(stk_a, stk_b, cost_a, cost_b);
}
