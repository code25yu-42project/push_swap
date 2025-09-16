#include "checker.h"

int	main(int argc, char *argv[])
{
	t_stacklst	*stacklst;
	int			return_check;
	char		*cmd_gnl;

	stacklst = NULL;
	if (argc == 1)
		return (0);
	return_check = ft_set_chk_argcv(&stacklst, --argc, ++argv);
	if (return_check == MALLOC_ERROR)
		return (return_check);
	else if (return_check < 0)
	{
		ft_free_stacklst(&stacklst);
		return (return_check);
	}
	cmd_gnl = get_next_line(0);
	if (ft_center_stack_sort_cmd(&stacklst, cmd_gnl) == 0)
	{
		ft_free_str(&cmd_gnl);
		return (0);
	}
	ft_ok_ko(&stacklst);
	ft_free_str(&cmd_gnl);
	ft_free_stacklst(&stacklst);
	return (0);
}

int	ft_center_stack_sort_cmd(t_stacklst **stacklst, char *cmd_gnl)
{
	if (ft_is_stack_sort_cmd(stacklst, cmd_gnl) == 0)
	{	
		ft_free_stacklst(stacklst);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}

void	ft_ok_ko(t_stacklst **stacklst)
{
	if ((*stacklst)->size_a == (*stacklst)->size_data
		&& ft_is_int_sorted((*stacklst)->head_a, (*stacklst)->size_a) == TRUE)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
