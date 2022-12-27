/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:35:50 by hwong             #+#    #+#             */
/*   Updated: 2022/12/28 01:35:59 by hwong            ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_stk	*stk_a;
	t_stk	*stk_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av))
		exit_error(NULL, NULL);
	stk_b = NULL;
	stk_a = fill_stack_values(ac, av);
	stack_size = get_stk_size(stk_a);
	assign_index(stk_a, stack_size + 1);
	push_swap(&stk_a, &stk_b, stack_size);
	free_stack(&stk_a);
	free_stack(&stk_b);
	return (0);
}
