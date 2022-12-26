/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:25:42 by hwong             #+#    #+#             */
/*   Updated: 2022/12/27 01:25:42 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	check_rules3(t_rules *rules)
{
	if (ft_strncmp_end(rules->data, "ra", 2) &&\
			ft_strncmp_end(rules->data, "rb", 2) &&\
			ft_strncmp_end(rules->data, "rr", 2) &&\
			ft_strncmp_end(rules->data, "pa", 2) &&\
			ft_strncmp_end(rules->data, "pb", 2) &&\
			ft_strncmp_end(rules->data, "sa", 2) &&\
			ft_strncmp_end(rules->data, "sb", 2) &&\
			ft_strncmp_end(rules->data, "ss", 2))
		return (0);
	else
		return (1);
}

static int	check_rules2(t_rules *rules)
{
	if (ft_strncmp_end(rules->data, "rra", 3) &&\
			ft_strncmp_end(rules->data, "rrb", 3) &&\
			ft_strncmp_end(rules->data, "rrr", 3))
		return (0);
	else
		return (1);
}

int			check_rules(t_rules *rules)
{
	int len;

	len = 0;
	while (rules)
	{
		len = ft_strlen(rules->data);
		if ((len == 3 && !check_rules2(rules)) ||\
				(len == 2 && !check_rules3(rules)) ||\
				(len != 3 && len != 2))
			return (0);
		rules = rules->next;
	}
	return (1);
}
