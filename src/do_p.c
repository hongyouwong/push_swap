/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:33:50 by hwong             #+#    #+#             */
/*   Updated: 2023/01/02 14:12:56 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stk **src, t_stk **dest)
{
	t_stk	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	do_pa(t_stk **stk_a, t_stk **stk_b)
{
	push(stk_b, stk_a);
	ft_putstr("pa\n");
}

void	do_pb(t_stk **stk_a, t_stk **stk_b)
{
	push(stk_a, stk_b);
	ft_putstr("pb\n");
}
