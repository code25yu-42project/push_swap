#include "common.h"

void	ft_ra(t_stacklst **stacklst)
{
	ft_rotate_head(&((*stacklst)->head_a));
	if ((*stacklst)->print_set)
		(*stacklst)->cmd[((*stacklst)->cmd_idx)++] = RA;
}

void	ft_rb(t_stacklst **stacklst)
{
	ft_rotate_head(&((*stacklst)->head_b));
	if ((*stacklst)->print_set)
		(*stacklst)->cmd[((*stacklst)->cmd_idx)++] = RB;
}

void	ft_rr(t_stacklst **stacklst)
{
	ft_rotate_head(&((*stacklst)->head_a));
	ft_rotate_head(&((*stacklst)->head_b));
	if ((*stacklst)->print_set)
		(*stacklst)->cmd[((*stacklst)->cmd_idx)++] = RR;
}
