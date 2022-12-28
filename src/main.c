/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:35:50 by hwong             #+#    #+#             */
/*   Updated: 2022/12/28 09:55:10 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stk *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_stk **stk_a, t_stk **stk_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stk_a))
		do_sa(stk_a);
	else if (stack_size == 3)
		tiny_sort(stk_a);
	else if (stack_size > 3 && !is_sorted(*stk_a))
		sort(stk_a, stk_b);
}

/*
*	check that ./push_swap was called with at least 1 arg
*	check if input was valid
*	fill stk_a with input
*	index the values in stk_a
*	throw the filled stk_a and empty stk_b to the push_swap function
*/
int	main(int argc, char **argv)
{
	t_stk	*stk_a;
	t_stk	*stk_b;
	int		stack_size;

	if (argc > 1)
	{
		if (!is_correct_input(argv))
			exit_error(NULL, NULL);
		stk_b = NULL;
		stk_a = fill_stack_values(argc, argv);
		stack_size = get_stk_size(stk_a);
		assign_index(stk_a, stack_size + 1);
		push_swap(&stk_a, &stk_b, stack_size);
		free_stack(&stk_a);
		free_stack(&stk_b);
	}
	return (0);
}
