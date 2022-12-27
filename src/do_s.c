/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:34:05 by hwong             #+#    #+#             */
/*   Updated: 2022/12/28 01:34:05 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stk *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}
void	do_sa(t_stk **stk_a)
{
	swap(*stk_a);
	ft_putstr("sa\n");
}

void	do_sb(t_stk **stk_b)
{
	swap(*stk_b);
	ft_putstr("sb\n");
}

void	do_ss(t_stk **stk_a, t_stk **stk_b)
{
	swap(*stk_a);
	swap(*stk_b);
	ft_putstr("ss\n");
}
