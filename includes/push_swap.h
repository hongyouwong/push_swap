/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 00:51:52 by hwong             #+#    #+#             */
/*   Updated: 2023/01/02 14:40:25 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stk
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stk	*next;
}	t_stk;

/* Initialization */

t_stk		*fill_stack_values(int argc, char **argv);
void		assign_index(t_stk *stk_a, int argc);

/* Sorting Algorithms */

int			is_sorted(t_stk *stk);
void		tiny_sort(t_stk **stk);
void		sort(t_stk **stk_a, t_stk **stk_b);

/* Position */

int			get_lowest_index_position(t_stk **stk);
void		get_target_position(t_stk **stk_a, t_stk **stk_b);

/* Cost */

void		get_cost(t_stk **stk_a, t_stk **stk_b);
void		do_cheapest_move(t_stk **stk_a, t_stk **stk_b);

/* Calculate Move */

void		do_move(t_stk **a, t_stk **b, int cost_a, int cost_b);

/* Operations */

void		do_pa(t_stk **stk_a, t_stk **stk_b);
void		do_pb(t_stk **stk_a, t_stk **stk_b);
void		do_sa(t_stk **stk_a);
void		do_sb(t_stk **stk_b);
void		do_ss(t_stk **stk_a, t_stk **stk_b);
void		do_ra(t_stk **stk_a);
void		do_rb(t_stk **stk_b);
void		do_rr(t_stk **stk_a, t_stk **stk_b);
void		do_rrr(t_stk **stk_a, t_stk **stk_b);
void		do_rra(t_stk **stk_a);
void		do_rrb(t_stk **stk_b);

/* Stack Functions */

t_stk		*get_stk_bottom(t_stk *stk);
t_stk		*get_stk_before_bottom(t_stk *stk);
t_stk		*stack_new(int value);
void		stk_add_bottom(t_stk **stk, t_stk *new);
int			get_stk_size(t_stk	*stk);

/* Utils */

void		free_stack(t_stk **stk);
long int	ft_atoi(const char *str);
void		ft_putstr(char *str);
int			nb_abs(int nb);
size_t		slen(const char *s);

/* Error */

void		exit_error(t_stk **stk_a, t_stk **stk_b);

/* Input Check */

int			is_correct_input(char **argv);
int			is_digit(char c);
int			is_sign(char c);
int			numstr_cmp(const char *s1, const char *s2);

#endif