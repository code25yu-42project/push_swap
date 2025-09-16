#include "common.h"

int	ft_sa(t_stacklst **stacklst)
{
	if ((*stacklst)->head_a == NULL \
	|| (*stacklst)->head_a->next == NULL)
		return (0);
	ft_swap_head(&((*stacklst)->head_a));
	if ((*stacklst)->print_set)
		(*stacklst)->cmd[((*stacklst)->cmd_idx)++] = SA;
	return (1);
}

int	ft_sb(t_stacklst **stacklst)
{
	if ((*stacklst)->head_b == NULL \
	|| (*stacklst)->head_b->next == NULL)
		return (0);
	ft_swap_head(&((*stacklst)->head_b));
	if ((*stacklst)->print_set)
		(*stacklst)->cmd[((*stacklst)->cmd_idx)++] = SB;
	return (1);
}

int	ft_ss(t_stacklst **stacklst)
{
	ft_sa(stacklst);
	ft_sb(stacklst);
	if ((*stacklst)->print_set)
		(*stacklst)->cmd[((*stacklst)->cmd_idx)++] = SS;
	return (1);
}
