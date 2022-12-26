/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:26:49 by hwong             #+#    #+#             */
/*   Updated: 2022/12/27 01:26:50 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int arg, char **argc)
{
	t_stack	*root_a;
	t_stack	*root_b;
	char	**tab;
	int		size;

	root_a = NULL;
	root_b = NULL;
	tab = (arg == 2) ? ft_strsplit(argc[1], ' ') : NULL;
	size = (arg == 2) ? ft_tab_size(tab) : 0;
	(arg == 2) ? error_check(size, tab, 1) :\
	error_check(arg, argc, 0);
	(arg == 2) ? push_args(size, tab, &root_a, 'a') :\
	push_args(arg, argc, &root_a, 'a');
	(arg == 2) ? free_tab(tab) : 0;
	error_doubles(root_a);
	sort_stack(&root_a, &root_b);
	return (0);
}
