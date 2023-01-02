/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 01:36:20 by hwong             #+#    #+#             */
/*   Updated: 2023/01/02 14:53:03 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*get_stk_bottom(t_stk *stk)
{
	while (stk && stk->next != NULL)
		stk = stk->next;
	return (stk);
}

t_stk	*get_stk_before_bottom(t_stk *stk)
{
	while (stk && stk->next && stk->next->next != NULL)
		stk = stk->next;
	return (stk);
}

/*
*	Creates a stack elements with the provided value.
*	Returns the newly created stack element.
*/
t_stk	*stack_new(int value)
{
	t_stk	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	stk_add_bottom(t_stk **stk, t_stk *new)
{
	t_stk	*tail;

	if (!new)
		return ;
	if (!*stk)
	{
		*stk = new;
		return ;
	}
	tail = get_stk_bottom(*stk);
	tail->next = new;
}

int	get_stk_size(t_stk	*stk)
{
	int	size;

	size = 0;
	if (!stk)
		return (0);
	while (stk)
	{
		stk = stk->next;
		size++;
	}
	return (size);
}
