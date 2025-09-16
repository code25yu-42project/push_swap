#include "checker.h"

int	ft_cmd_sort_threechr(t_stacklst **stacklst, \
						char *cmd_gnl, int cmd_idx, int cmd_size)
{
	if (ft_strnstr(cmd_gnl + cmd_idx, "rra", cmd_size) != 0)
		ft_rra(stacklst);
	else if (ft_strnstr(cmd_gnl + cmd_idx, "rrb", cmd_size) != 0)
		ft_rrb(stacklst);
	else if (ft_strnstr(cmd_gnl + cmd_idx, "rrr", cmd_size) != 0)
		ft_rrr(stacklst);
	else
		return (0);
	return (1);
}

int	ft_cmd_sort_twochr(t_stacklst **stacklst, \
						char *cmd_gnl, int cmd_idx, int cmd_size)
{
	if (ft_strnstr(cmd_gnl + cmd_idx, "sa", cmd_size) != 0)
		ft_sa(stacklst);
	else if (ft_strnstr(cmd_gnl + cmd_idx, "sb", cmd_size) != 0)
		ft_sb(stacklst);
	else if (ft_strnstr(cmd_gnl + cmd_idx, "ss", cmd_size) != 0)
		ft_ss(stacklst);
	else if (ft_strnstr(cmd_gnl + cmd_idx, "pa", cmd_size) != 0)
		ft_pa(stacklst, NULL);
	else if (ft_strnstr(cmd_gnl + cmd_idx, "pb", cmd_size) != 0)
		ft_pb(stacklst, NULL);
	else if (ft_strnstr(cmd_gnl + cmd_idx, "ra", cmd_size) != 0)
		ft_ra(stacklst);
	else if (ft_strnstr(cmd_gnl + cmd_idx, "rb", cmd_size) != 0)
		ft_rb(stacklst);
	else if (ft_strnstr(cmd_gnl + cmd_idx, "rr", cmd_size) != 0)
		ft_rr(stacklst);
	else
		return (0);
	return (1);
}

int	ft_is_stack_sort_cmd(t_stacklst **stacklst, char *cmd)
{
	int	idx;
	int	size;

	idx = 0;
	(*stacklst)->size_b = 2;
	while (cmd && cmd[idx])
	{
		size = 0;
		while (cmd && cmd[idx + size] && cmd[idx + size] != '\n')
			size++;
		if (size == 3 && cmd[idx + size] == '\n')
		{
			if (ft_cmd_sort_threechr(stacklst, cmd, idx, size) == 0)
				return (0);
		}
		else if (size == 2 && cmd[idx + size] == '\n')
		{
			if (ft_cmd_sort_twochr(stacklst, cmd, idx, size) == 0)
				return (0);
		}
		else
			return (0);
		idx += (size + 1);
	}
	return (1);
}
