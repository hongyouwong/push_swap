/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:33:55 by hwong             #+#    #+#             */
/*   Updated: 2022/12/28 01:33:56 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stk **stk)
{
	t_stk	*tmp;
	t_stk	*tail;

	tmp = *stk;
	*stk = (*stk)->next;
	tail = get_stk_bottom(*stk);
	tmp->next = NULL;
	tail->next = tmp;
}

void	do_ra(t_stk **stk_a)
{
	rotate(stk_a);
	ft_putstr("ra\n");
}

void	do_rb(t_stk **stk_b)
{
	rotate(stk_b);
	ft_putstr("rb\n");
}

void	do_rr(t_stk **stk_a, t_stk **stk_b)
{
	rotate(stk_a);
	rotate(stk_b);
	ft_putstr("rr\n");
}
