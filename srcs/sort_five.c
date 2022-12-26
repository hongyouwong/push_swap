/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:26:59 by hwong             #+#    #+#             */
/*   Updated: 2022/12/27 01:27:00 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_last(t_stack **root_a, int lo, int size)
{
	if (size == 5)
	{
		if (lo == (*root_a)->next->next->next->next->data)
			reverse_rotate(root_a);
	}
	if (lo == (*root_a)->next->next->next->data)
	{
		reverse_rotate(root_a);
		size == 5 ? reverse_rotate(root_a) : 0;
	}
}

static void	push_lowest(t_stack **root_a, t_stack **root_b, int lo, int size)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if ((*root_a)->data == lo)
		{
			push_ab(root_a, root_b);
			size == 5 ? push_ab(root_a, root_b) : 0;
			i = 2;
		}
		else
			rotate(root_a);
	}
}

static void	check_worst_case(t_stack **root_a, t_stack **root_b)
{
	if ((*root_b)->data > (*root_a)->next->data &&\
			(*root_b)->data < (*root_a)->next->next->data)
	{
		reverse_rotate(root_a);
		push_ab(root_b, root_a);
		rotate(root_a);
		rotate(root_a);
	}
}

void		sort_five(t_stack **root_a, t_stack **root_b, int lo, int size)
{
	check_last(root_a, lo, size);
	push_lowest(root_a, root_b, lo, size);
	sort_three(root_a);
	if (size == 4)
	{
		push_ab(root_b, root_a);
		return ;
	}
	check_worst_case(root_a, root_b);
	push_ab(root_b, root_a);
	if ((*root_a)->data > (*root_a)->next->data &&\
			(*root_a)->data < (*root_a)->next->next->data)
		swap(root_a);
	else if ((*root_a)->data > (*root_a)->next->next->next->data)
		rotate(root_a);
	push_ab(root_b, root_a);
}
