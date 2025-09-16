#include "push_swap.h"

int	ft_print_cmd_single(t_stacklst **stacklst, int idx)
{
	if ((*stacklst)->cmd[idx] == SA)
		ft_putstr_fd("sa\n", 1);
	else if ((*stacklst)->cmd[idx] == SB)
		ft_putstr_fd("sb\n", 1);
	else if ((*stacklst)->cmd[idx] == PA)
		ft_putstr_fd("pa\n", 1);
	else if ((*stacklst)->cmd[idx] == PB)
		ft_putstr_fd("pb\n", 1);
	else if ((*stacklst)->cmd[idx] == RA)
		ft_putstr_fd("ra\n", 1);
	else if ((*stacklst)->cmd[idx] == RB)
		ft_putstr_fd("rb\n", 1);
	else if ((*stacklst)->cmd[idx] == RRA)
		ft_putstr_fd("rra\n", 1);
	else if ((*stacklst)->cmd[idx] == RRB)
		ft_putstr_fd("rrb\n", 1);
	else if ((*stacklst)->cmd[idx] == RRR)
		ft_putstr_fd("rrr\n", 1);
	else
		return (0);
	return (1);
}

int	ft_print_cmd_double(t_stacklst **stacklst, int idx)
{
	if ((*stacklst)->cmd[idx] == RA \
	&& (*stacklst)->cmd[idx + 1] == RRR \
	&& (*stacklst)->size_data == 5)
		ft_putstr_fd("rb\n", 1);
	else if ((*stacklst)->cmd[idx] == SA \
				&& (*stacklst)->cmd[idx + 1] == SB)
		ft_putstr_fd("ss\n", 1);
	else if ((*stacklst)->cmd[idx] == RA \
				&& (*stacklst)->cmd[idx + 1] == RB)
		ft_putstr_fd("rr\n", 1);
	else if ((*stacklst)->cmd[idx] == RRA \
				&& (*stacklst)->cmd[idx + 1] == RRB)
		ft_putstr_fd("rrr\n", 1);
	else
		return (0);
	return (1);
}

void	ft_print_cmd(t_stacklst **stacklst)
{
	int	idx;

	idx = 0;
	while ((*stacklst)->cmd && (*stacklst)->cmd[idx])
	{
		if ((*stacklst)->cmd[idx + 1] \
			&& ft_print_cmd_double(stacklst, idx) == 1)
		{
			idx += 2;
			continue ;
		}
		if (ft_print_cmd_single(stacklst, idx) == 1)
			idx++;
	}
}
