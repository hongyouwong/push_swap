/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:26:07 by hwong             #+#    #+#             */
/*   Updated: 2022/12/27 01:26:08 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	read_instructions(t_rules **rules)
{
	int		ret;
	char	*line;
	int		nbr;

	nbr = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (ft_strlen(line) > 3 || ft_strlen(line) < 2)
		{
			free(line);
			return (0);
		}
		push_rules(rules, line);
		free(line);
	}
	if (ret == -1)
		return (0);
	return (1);
}
