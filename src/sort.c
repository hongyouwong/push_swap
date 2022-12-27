/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:36:15 by hwong             #+#    #+#             */
/*   Updated: 2022/12/28 01:36:16 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push_all_save_three:
*	Pushes all the elements of stack a into stack b, except the three last ones.
*	Pushes the smaller values first, and then the larger values to help with
*	sorting efficiency.
*/
static void	push_all_save_three(t_stk **stk_a, t_stk **stk_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stk_size(*stk_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stk_a)->index <= stack_size / 2)
		{
			do_pb(stk_a, stk_b);
			pushed++;
		}
		else
			do_ra(stk_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		do_pb(stk_a, stk_b);
		pushed++;
	}
}

/* shift_stk:
*	After the bulk of the stack is sorted, shifts stack a until the lowest
*	value is at the top. If it is in the bottom half of the stack, reverse
*	rotate it into position, otherwise rotate until it is at the top of the
*	stack.
*/
static void	shift_stk(t_stk **stk_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stk_size(*stk_a);
	lowest_pos = get_lowest_index_position(stk_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			do_rra(stk_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(stk_a);
			lowest_pos--;
		}
	}
}

/* sort:
*	Sorting algorithm for a stack larger than 3.
*		Push everything but 3 numbers to stack B.
*		Sort the 3 numbers left in stack A.
*		Calculate the most cost-effective move.
*		Shift elements until stack A is in order.
*/
void	sort(t_stk **stk_a, t_stk **stk_b)
{
	push_all_save_three(stk_a, stk_b);
	tiny_sort(stk_a);
	while (*stk_b)
	{
		get_target_position(stk_a, stk_b);
		get_cost(stk_a, stk_b);
		do_cheapest_move(stk_a, stk_b);
	}
	if (!is_sorted(*stk_a))
		shift_stk(stk_a);
}
