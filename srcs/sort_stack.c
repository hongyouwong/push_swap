/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:27:07 by hwong             #+#    #+#             */
/*   Updated: 2022/12/27 01:27:08 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	count_stack_size(t_stack *root_a, int *lo)
{
	int		size;
	t_stack *current;

	current = root_a;
	size = 0;
	while (current)
	{
		*lo = current->data < *lo ? current->data : *lo;
		current = current->next;
		size++;
	}
	return (size);
}

void		sort_stack(t_stack **root_a, t_stack **root_b)
{
	int		size;
	int		lo;

	lo = (*root_a)->data;
	size = count_stack_size(*root_a, &lo);
	if (check_order(*root_a, *root_b))
	{
		free_stack(*root_a);
		exit(0);
	}
	if (size == 2 && (*root_a)->data > (*root_a)->next->data)
		rotate(root_a);
	else if (size == 3)
		sort_three(root_a);
	else if (size == 4 || size == 5)
		sort_five(root_a, root_b, lo, size);
	else if (size > 5)
		big_sort(root_a, root_b, size);
}
