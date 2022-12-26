/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:26:01 by hwong             #+#    #+#             */
/*   Updated: 2022/12/27 01:26:02 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	check_rr(t_stack **root_a, t_stack **root_b, t_rules *rules)
{
	!ft_strncmp_end(rules->data, "rra", 3) ? reverse_rotate(root_a) : 0;
	!ft_strncmp_end(rules->data, "rrb", 3) ? reverse_rotate(root_b) : 0;
	!ft_strncmp_end(rules->data, "rrr", 3) ? rev_rot_both(root_a, root_b) : 0;
}

static void	check_r(t_stack **root_a, t_stack **root_b, t_rules *rules)
{
	!ft_strncmp_end(rules->data, "ra", 2) ? rotate(root_a) : 0;
	!ft_strncmp_end(rules->data, "rb", 2) ? rotate(root_b) : 0;
	!ft_strncmp_end(rules->data, "rr", 2) ? rotate_both(root_a, root_b) : 0;
}

static void	check_push(t_stack **root_a, t_stack **root_b, t_rules *rules)
{
	!ft_strncmp_end(rules->data, "pa", 2) ? push_ab(root_b, root_a) : 0;
	!ft_strncmp_end(rules->data, "pb", 2) ? push_ab(root_a, root_b) : 0;
}

static void	check_swap(t_stack **root_a, t_stack **root_b, t_rules *rules)
{
	!ft_strncmp_end(rules->data, "sa", 2) ? swap(root_a) : 0;
	!ft_strncmp_end(rules->data, "sb", 2) ? swap(root_b) : 0;
	!ft_strncmp_end(rules->data, "ss", 2) ? swap_both(root_a, root_b) : 0;
}

void		execute_rules(t_stack **root_a, t_stack **root_b, t_rules *rules)
{
	int	size;

	size = count_rules(rules);
	print_start(*root_a, *root_b);
	while (rules)
	{
		check_swap(root_a, root_b, rules);
		check_push(root_a, root_b, rules);
		check_r(root_a, root_b, rules);
		check_rr(root_a, root_b, rules);	
		print_steps(*root_a, *root_b, rules->data);
		rules = rules->next;
	}
	print_lines(*root_a, size);
	free(rules);
}
