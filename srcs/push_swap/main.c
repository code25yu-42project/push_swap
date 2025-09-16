#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stacklst	*stacklst;
	int			return_check;

	stacklst = NULL;
	return_check = 0;
	return_check = ft_set_chk_argcv(&stacklst, --argc, ++argv);
	if (return_check == MALLOC_ERROR)
		return (return_check);
	else if (return_check <= 0)
	{
		ft_free_stacklst(&stacklst);
		return (return_check);
	}
	ft_quick_sort(&stacklst, stacklst->size_a);
	ft_free_stacklst(&stacklst);
	return (0);
}
