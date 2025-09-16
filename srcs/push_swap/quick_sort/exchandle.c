#include "push_swap.h"

void	ft_qs_two_arg(t_stacklst **stacklst, int *right, int pivot2)
{
	if ((*right) - pivot2 == 1)
	{
		if ((*stacklst)->head_a->data == ((*stacklst)->head_a->next->data) + 1)
			ft_sa(stacklst);
		(*right)--;
	}
}
