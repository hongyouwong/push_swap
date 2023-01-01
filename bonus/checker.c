#include "push_swap.h"

void	err_exit(void)
{
	write(1, "Invalid move, exiting...\n", 25);
	exit(1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] && s2[i]) && (s1[i] == s2[i]) && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	run_cmd(char *cmd, t_stk **stk_a, t_stk **stk_b)
{
	if (!ft_strncmp(cmd, "sa\n", 3))
		do_sa(stk_a);
	else if (!ft_strncmp(cmd, "sb\n", 4))
		do_sb(stk_b);
	else if (!ft_strncmp(cmd, "ss\n", 4))
		do_ss(stk_a, stk_b);
	else if (!ft_strncmp(cmd, "pa\n", 4))
		do_pa(stk_a, stk_b);
	else if (!ft_strncmp(cmd, "pb\n", 4))
		do_pb(stk_a, stk_b);
	else if (!ft_strncmp(cmd, "ra\n", 4))
		do_ra(stk_a);
	else if (!ft_strncmp(cmd, "rb\n", 4))
		do_rb(stk_b);
	else if (!ft_strncmp(cmd, "rr\n", 4))
		do_rr(stk_a, stk_b);
	else if (!ft_strncmp(cmd, "rra\n", 5))
		do_rra(stk_a);
	else if (!ft_strncmp(cmd, "rrb\n", 5))
		do_rrb(stk_b);
	else if (!ft_strncmp(cmd, "rrr\n", 5))
		do_rrr(stk_a, stk_b);
	else
		err_exit();
}

void	handle_inputs(t_stk **stk_a, t_stk **stk_b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		run_cmd(cmd, stk_a, stk_b);
		free(cmd);
		cmd = get_next_line(0);
	}
	if (is_sorted(*stk_a))
		write(1, "\033[1;32mOK\n", 1);
	else
		write(1, "\033[1;31mKO\n", 1);

}

int	main(int argc, char **argv)
{
	t_stk	*stk_a;
	t_stk	*stk_b;

	if (argc == 1)
		return (0);
	argv++;
	stk_a = fill_stack_values(argc, argv);
	stk_b = NULL;
	handle_inputs(&stk_a, &stk_b);
}
