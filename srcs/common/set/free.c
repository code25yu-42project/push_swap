#include "common.h"

void	ft_free_new_argv(char **new_argv)
{
	int	idx;

	idx = 0;
	while (new_argv[idx])
	{
		free(new_argv[idx]);
		new_argv[idx++] = 0;
	}
	free(new_argv);
	new_argv = NULL;
}

int	ft_free_new_argv_error(char **new_argv)
{
	ft_free_new_argv(new_argv);
	return (PRINT_ERROR);
}

int	ft_free_new_argv_nothing(char **new_argv)
{
	ft_free_new_argv(new_argv);
	return (PRINT_NOTHING);
}

int	ft_free_new_argv_malloc(char **new_argv)
{
	ft_free_new_argv(new_argv);
	return (MALLOC_ERROR);
}

void	ft_free_stacklst(t_stacklst **stacklst)
{
	if (!(*stacklst))
		return ;
	if ((*stacklst)->free_head)
	{
		free((*stacklst)->free_head);
		(*stacklst)->free_head = NULL;
	}
	if ((*stacklst)->cmd)
	{
		free((*stacklst)->cmd);
		(*stacklst)->cmd = NULL;
	}
	if (*stacklst)
	{
		free(*stacklst);
		(*stacklst) = NULL;
	}
}
