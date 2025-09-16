#include "common.h"

int	ft_is_strptr_space(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str && str[i])
	{
		j = 0;
		while (str[i] && str[i][j])
		{
			if (str[i][j] == ' ')
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

char	*ft_join_argv(char **argv, char	**join_argv)
{
	int		join_idx;
	char	*tmp;

	join_idx = 0;
	while (*(argv + join_idx))
	{
		tmp = *join_argv;
		*join_argv = ft_strjoin(tmp, *(argv + join_idx));
		if (*join_argv == NULL)
			return (*join_argv);
		ft_free_str(&tmp);
		tmp = *join_argv;
		*join_argv = ft_strjoin(tmp, " ");
		if (*join_argv == NULL)
			return (*join_argv);
		ft_free_str(&tmp);
		join_idx++;
	}
	return (*join_argv);
}

void	ft_free_str(char **str)
{
	free(*str);
	*str = NULL;
}

char	**ft_set_argcv(int *argc, char **argv)
{
	char	**join_argv;
	char	**split_argv;
	int		argv_size;

	if (*argc == 0)
		return (0);
	join_argv = (char **)malloc(sizeof(char *));
	if (join_argv == NULL)
		return (NULL);
	*join_argv = NULL;
	split_argv = NULL;
	argv_size = 0;
	if (ft_join_argv(argv, join_argv) == NULL)
		ft_free_str(join_argv);
	if (*join_argv)
		split_argv = ft_split(*join_argv, ' ');
	if (split_argv == NULL)
		return (split_argv);
	while (split_argv[argv_size])
		argv_size++;
	*argc = argv_size;
	ft_free_str(join_argv);
	free(join_argv);
	join_argv = NULL;
	return (split_argv);
}
