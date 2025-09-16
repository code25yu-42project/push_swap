#include "common.h"

void	ft_rra(t_stacklst **stacklst)
{
	ft_rotate_tail(&((*stacklst)->head_a));
	if ((*stacklst)->print_set)
		(*stacklst)->cmd[((*stacklst)->cmd_idx)++] = RRA;
}

void	ft_rrb(t_stacklst **stacklst)
{
	ft_rotate_tail(&((*stacklst)->head_b));
	if ((*stacklst)->print_set)
		(*stacklst)->cmd[((*stacklst)->cmd_idx)++] = RRB;
}

void	ft_rrr(t_stacklst **stacklst)
{
	ft_rotate_tail(&((*stacklst)->head_a));
	ft_rotate_tail(&((*stacklst)->head_b));
	if ((*stacklst)->print_set)
		(*stacklst)->cmd[((*stacklst)->cmd_idx)++] = RRR;
}
