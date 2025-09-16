#include "push_swap.h"

void	ft_qs_stacka(t_stacklst **stacklst, int left, int right)
{
	int	loop_ft_partition;
	int	loop_ft_rrr;
	int	pivot1;
	int	pivot2;

	ft_pivot(right - left + 1, &pivot1, &pivot2, 'a');
	pivot1 += left;
	pivot2 += left;
	loop_ft_partition = right - left + 1;
	if ((*stacklst)->size_data == loop_ft_partition)
		ft_qs_stacka_loop_first(stacklst, loop_ft_partition, pivot1, pivot2);
	else
	{
		ft_qs_stacka_loop(stacklst, loop_ft_partition, pivot1, pivot2);
		loop_ft_rrr = pivot2 - pivot1;
		while (loop_ft_rrr-- && (*stacklst)->head_a && (*stacklst)->head_b)
			ft_rrr(stacklst);
	}
	ft_qs_two_arg(stacklst, &right, pivot2);
	if (pivot2 < right)
		ft_qs_stacka(stacklst, pivot2, right);
	if (pivot1 < pivot2)
		ft_qs_stackb(stacklst, pivot1, pivot2 - 1);
	if (left < pivot1)
		ft_qs_stackb(stacklst, left, pivot1 - 1);
}

void	ft_qs_stackb(t_stacklst **stacklst, int left, int right)
{
	int	loop_ft_partition;
	int	loop_ft_rrr;
	int	pivot1;
	int	pivot2;

	ft_pivot(right - left + 1, &pivot1, &pivot2, 'b');
	pivot1 += left;
	pivot2 += left;
	loop_ft_partition = right - left + 1;
	ft_qs_stackb_loop (stacklst, loop_ft_partition, pivot1, pivot2);
	ft_qs_two_arg(stacklst, &right, pivot2);
	if (pivot2 < right)
		ft_qs_stacka(stacklst, pivot2, right);
	loop_ft_rrr = pivot2 - pivot1;
	while (loop_ft_rrr-- && (*stacklst)->head_a && (*stacklst)->head_b)
		ft_rrr(stacklst);
	if (pivot1 + 1 < pivot2)
		ft_qs_stacka(stacklst, pivot1, pivot2 - 1);
	if (left < pivot1)
		ft_qs_stackb(stacklst, left, pivot1 - 1);
}
