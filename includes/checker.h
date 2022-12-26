/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:25:01 by hwong             #+#    #+#             */
/*   Updated: 2022/12/27 01:25:12 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../lib/lib.h"

int		main(int arg, char **argc);
int		read_instructions(t_rules **rules);
void	push_ab(t_stack **root, t_stack **stack);
void	swap(t_stack **root);
void	reverse_rotate(t_stack **root);
void	rotate(t_stack **root);
void	execute_rules(t_stack **root_a, t_stack **root_b, t_rules *rules);
int		check_rules(t_rules *rules);

#endif
