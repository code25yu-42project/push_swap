#include "common.h"

void	ft_bubble_sort(t_stacklst **stacklst, t_stack *now, \
						int loop, char data_idx)
{
	int	bubble;
	int	now_data;
	int	next_data;

	while (--loop)
	{
		now = (*stacklst)->head_a;
		bubble = loop;
		while (bubble--)
		{
			if (data_idx == 'd')
			{
				now_data = now->data;
				next_data = now->next->data;
			}
			else
			{
				now_data = now ->idx;
				next_data = now->next->idx;
			}
			if (now_data > next_data)
				ft_swap_head(&now);
			now = now->next;
		}
	}
}

void	ft_indexing_stack(t_stack *stack, int stack_size)
{
	int	idx;

	idx = 0;
	while (idx < stack_size)
	{
		stack->data = idx++;
		stack = stack->next;
	}
}
