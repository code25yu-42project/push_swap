#include "common.h"

int	ft_isempty(t_stack *head)
{
	if (head == NULL)
		return (TRUE);
	return (FALSE);
}

int	ft_isfull(int data_size, int stack_size)
{
	if (stack_size == data_size)
		return (TRUE);
	return (FALSE);
}
