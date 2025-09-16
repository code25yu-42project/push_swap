#include "common.h"

int	ft_malloc_stacklst(t_stacklst **stacklst, int size)
{
	(*stacklst) = (t_stacklst *)malloc(sizeof(t_stacklst));
	if ((*stacklst) == NULL)
		return (MALLOC_ERROR);
	ft_memset((*stacklst), 0, sizeof(t_stacklst));
	(*stacklst)->size_data = size;
	(*stacklst)->head_a \
		= (t_stack *)malloc(sizeof(t_stack) * (*stacklst)->size_data + 1);
	(*stacklst)->free_head = (*stacklst)->head_a;
	(*stacklst)->cmd \
		= (char *)malloc(sizeof(char) * (*stacklst)->size_data * 20 + 1);
	if ((*stacklst)->head_a == NULL)
	{
		free((*stacklst));
		return (MALLOC_ERROR);
	}
	if ((*stacklst)->cmd == NULL)
	{
		free((*stacklst)->head_a);
		free((*stacklst));
		return (MALLOC_ERROR);
	}
	ft_memset((*stacklst)->head_a, 0, sizeof(t_stack));
	return (0);
}

int	ft_set_stack_a(t_stacklst **stacklst, t_stack *now, \
					int data_size, char **str)
{
	int			str_idx;
	long long	str_int;

	str_idx = 0;
	while (str_idx < data_size)
	{
		str_int = ft_atoi(str[str_idx]);
		if (ft_is_int(str_int) == FALSE)
			return (FALSE);
		now->data = str_int;
		now->idx = str_idx;
		ft_pa(stacklst, &now);
		ft_ra(stacklst);
		now = now + 1;
		str_idx++;
	}
	(*stacklst)->print_set = 1;
	return (1);
}
