/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:34:10 by hwong             #+#    #+#             */
/*   Updated: 2023/01/02 14:52:26 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*	Fills stk_a with the provided values.
*	If the values are out of integer range, prints and error and exits the program.
*/
t_stk	*fill_stack_values(int argc, char **argv)
{
	t_stk		*stk_a;
	long int	nb;
	int			i;

	stk_a = NULL;
	nb = 0;
	i = 1;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_error(&stk_a, NULL);
		if (i == 1)
			stk_a = stack_new((int)nb);
		else
			stk_add_bottom(&stk_a, stack_new((int)nb));
		i++;
	}
	return (stk_a);
}

/*
*	Assigns an index to each value in stack a. This is a convenient way to order
*	the stack because indexes can be checked and compared instead of actual values,
*	which may or may not be adjacent to each other.
*		ex. values:		-3	 0	 9	 2
*		indexes:		[1]	[2]	[4]	[3]
*	The indexes are assigned from highest (stack_size) to lowest (1).
*/
void	assign_index(t_stk *stk_a, int stack_size)
{
	t_stk	*ptr;
	t_stk	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stk_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stk_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
