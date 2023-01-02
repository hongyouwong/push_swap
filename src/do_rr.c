/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:34:00 by hwong             #+#    #+#             */
/*   Updated: 2023/01/02 14:13:14 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stk **stk)
{
	t_stk	*tmp;
	t_stk	*last;
	t_stk	*second_last;

	last = get_stk_bottom(*stk);
	second_last = get_stk_before_bottom(*stk);
	tmp = *stk;
	*stk = last;
	(*stk)->next = tmp;
	second_last->next = NULL;
}

void	do_rra(t_stk **stk_a)
{
	rev_rotate(stk_a);
	ft_putstr("rra\n");
}

void	do_rrb(t_stk **stk_b)
{
	rev_rotate(stk_b);
	ft_putstr("rrb\n");
}

void	do_rrr(t_stk **stk_a, t_stk **stk_b)
{
	rev_rotate(stk_a);
	rev_rotate(stk_b);
	ft_putstr("rrr\n");
}
