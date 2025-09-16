#include "common.h"

void	ft_swap_head(t_stack **head)
{
	t_stack		*a;
	t_stack		*b;
	int			a_data;
	int			a_idx;

	a = (*head);
	b = (*head)->next;
	a_data = a->data;
	a->data = b->data;
	b->data = a_data;
	a_idx = a->idx;
	a->idx = b->idx;
	b->idx = a_idx;
}

void	ft_rotate_head(t_stack **head)
{
	if (*head && (*head)->pre)
		(*head) = (*head)->next;
}

void	ft_rotate_tail(t_stack **head)
{
	if (*head && (*head)->pre)
		(*head) = (*head)->pre;
}
