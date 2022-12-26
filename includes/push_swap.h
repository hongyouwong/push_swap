/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:25:21 by hwong             #+#    #+#             */
/*   Updated: 2022/12/27 01:25:22 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../lib/lib.h"

int		main(int arg, char **argc);
void	sort_stack(t_stack **root_a, t_stack **root_b);
void	sort_three(t_stack **root_a);
void	sort_five(t_stack **root_a, t_stack **root_b, int lo, int size);
void	big_sort(t_stack **root_a, t_stack **root_b, int size);
int		shortest_way(t_stack *root, int value);

#endif
