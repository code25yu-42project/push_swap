#include "common.h"

int	ft_set_chk_argcv(t_stacklst **stacklst, int argc, char **argv)
{
	char	**new_argv;
	int		rtn_check;

	rtn_check = 0;
	new_argv = ft_set_argcv(&argc, argv);
	if (new_argv == NULL || *new_argv == NULL)
		return (MALLOC_ERROR);
	rtn_check = ft_chk_argv_digit(argc, new_argv);
	if (rtn_check == FALSE)
		return (ft_free_new_argv_error(new_argv));
	rtn_check = ft_malloc_stacklst(stacklst, argc);
	if (rtn_check == MALLOC_ERROR)
		return (ft_free_new_argv_malloc(new_argv));
	rtn_check = ft_set_stack_a(stacklst, (*stacklst)->head_a, argc, new_argv);
	if (rtn_check == FALSE)
		return (ft_free_new_argv_error(new_argv));
	rtn_check = ft_chk_argv_not_sorted(stacklst);
	if (rtn_check == FALSE)
		return (ft_free_new_argv_nothing(new_argv));
	rtn_check = ft_chk_argv_unique(stacklst);
	if (rtn_check == FALSE)
		return (ft_free_new_argv_error(new_argv));
	ft_index_sort(stacklst);
	ft_free_new_argv(new_argv);
	return (1);
}
