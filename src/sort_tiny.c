/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:36:09 by hwong             #+#    #+#             */
/*   Updated: 2023/01/02 14:52:10 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Returns the highest index in a stack.
*/
static int	find_highest_index(t_stk *stk)
{
	int		index;

	index = stk->index;
	while (stk)
	{
		if (stk->index > index)
			index = stk->index;
		stk = stk->next;
	}
	return (index);
}

/*
*	Sorts a stack of 3 numbers in 2 or fewer moves. The sorting is done by index
*	rather than value. Example:
*		values:		 0	 9	 2
*		indexes:	[1]	[3]	[2]
*	Solution, 2 moves:
*	rra:
*		values:		 2	 0	 9
*		indexes:	[2]	[1]	[3]
*	sa:
*		values:		 0	 2	 9
*		indexes:	[1]	[2]	[3]
*/
void	tiny_sort(t_stk **stk)
{
	int		highest;

	if (is_sorted(*stk))
		return ;
	highest = find_highest_index(*stk);
	if ((*stk)->index == highest)
		do_ra(stk);
	else if ((*stk)->next->index == highest)
		do_rra(stk);
	if ((*stk)->index > (*stk)->next->index)
		do_sa(stk);
}
