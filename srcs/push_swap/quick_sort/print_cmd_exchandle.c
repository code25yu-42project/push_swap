#include "push_swap.h"

void	ft_print_cmd_two_arg(t_stacklst **stacklst)
{
	if ((*stacklst)->head_a->data > (*stacklst)->head_a->next->data)
		ft_sa(stacklst);
}

void	ft_print_cmd_three_arg(t_stacklst **stacklst)
{
	int	cmp;

	cmp = ft_cmp_three_int((*stacklst)->head_a->data, \
						(*stacklst)->head_a->next->data, \
						(*stacklst)->head_a->next->next->data);
	if (cmp == 132)
	{
		ft_ra(stacklst);
		ft_sa(stacklst);
		ft_rra(stacklst);
	}
	else if (cmp == 213)
		ft_sa(stacklst);
	else if (cmp == 231)
		ft_rra(stacklst);
	else if (cmp == 312)
		ft_ra(stacklst);
	else if (cmp == 321)
	{
		ft_ra(stacklst);
		ft_sa(stacklst);
	}
}
