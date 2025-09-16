#include "push_swap.h"

void	ft_qs_stacka_loop_first(t_stacklst **stacklst, \
								int loop_ft_partition, int pivot1, int pivot2)
{
	while (loop_ft_partition--)
	{
		if ((*stacklst)->head_a->data >= pivot2)
			ft_ra(stacklst);
		else if ((*stacklst)->head_a->data >= pivot1)
			ft_pb(stacklst, NULL);
		else if ((*stacklst)->head_a->data < pivot1)
		{
			ft_pb(stacklst, NULL);
			ft_rb(stacklst);
		}
	}
}

void	ft_qs_stacka_loop(t_stacklst **stacklst, \
							int loop_ft_partition, int pivot1, int pivot2)
{
	while (loop_ft_partition-- && (*stacklst)->head_a)
	{
		if ((*stacklst)->head_a->data >= pivot2)
			ft_ra(stacklst);
		else if ((*stacklst)->head_a->data >= pivot1)
		{
			ft_pb(stacklst, NULL);
			ft_rb(stacklst);
		}
		else if ((*stacklst)->head_a->data < pivot1)
			ft_pb(stacklst, NULL);
	}
}

void	ft_qs_stackb_loop(t_stacklst **stacklst, \
							int loop_ft_partition, int pivot1, int pivot2)
{
	while (loop_ft_partition-- && (*stacklst)->head_b)
	{
		if ((*stacklst)->head_b->data >= pivot2)
			ft_pa(stacklst, NULL);
		else if ((*stacklst)->head_b->data >= pivot1)
		{
			ft_pa(stacklst, NULL);
			ft_ra(stacklst);
		}
		else if ((*stacklst)->head_b->data < pivot1)
			ft_rb(stacklst);
	}
}
