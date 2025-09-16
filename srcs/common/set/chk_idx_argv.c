#include "common.h"

void	ft_index_sort(t_stacklst **stacklst)
{
	ft_indexing_stack((*stacklst)->head_a, (*stacklst)->size_a);
	ft_bubble_sort(stacklst, (*stacklst)->head_a, (*stacklst)->size_a, 'i');
}

int	ft_chk_argv_unique(t_stacklst **stacklst)
{
	ft_bubble_sort(stacklst, (*stacklst)->head_a, (*stacklst)->size_a, 'd');
	if (ft_is_int_unique((*stacklst)->head_a, (*stacklst)->size_a) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	ft_chk_argv_not_sorted(t_stacklst **stacklst)
{
	if (ft_is_int_sorted((*stacklst)->head_a, (*stacklst)->size_a) == TRUE)
		return (FALSE);
	return (TRUE);
}

int	ft_chk_argv_digit(int argc, char **argv)
{
	if (ft_is_str_digit(argv, argc) == FALSE)
	{
		ft_putstr_fd("Error\n", 2);
		return (FALSE);
	}
	return (TRUE);
}
