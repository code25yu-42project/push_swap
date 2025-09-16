#include "common.h"

int	ft_is_str_digit(char **ptr_str, int len)
{
	int		ptr_idx;
	int		str_idx;
	char	chr;

	ptr_idx = 0;
	while (ptr_idx < len)
	{
		str_idx = 0;
		chr = ptr_str[ptr_idx][str_idx];
		if (chr == 0)
			return (FALSE);
		while (ptr_str[ptr_idx][str_idx])
		{
			chr = ptr_str[ptr_idx][str_idx];
			if (!(str_idx == 0 && (chr == '-' || chr == '+')) \
				&& !(ft_isdigit(chr)))
				return (FALSE);
			str_idx++;
		}
		ptr_idx++;
	}
	return (TRUE);
}

int	ft_is_int(long long str_int)
{
	if (str_int > INT_MAX || str_int < INT_MIN)
	{
		ft_putstr_fd("Error\n", 2);
		return (FALSE);
	}
	return (TRUE);
}

int	ft_is_int_unique(t_stack *stack, int stack_size)
{
	int	ptr_idx;

	ptr_idx = 0;
	while (ptr_idx + 1 < stack_size)
	{
		if (stack->data == stack->next->data)
		{
			ft_putstr_fd("Error\n", 2);
			return (FALSE);
		}
		ptr_idx++;
		stack = stack->next;
	}
	return (TRUE);
}

int	ft_is_int_sorted(t_stack *now, int stack_size)
{
	int	ptr_idx;

	ptr_idx = 0;
	while (now && ptr_idx + 1 < stack_size)
	{
		if (now->data >= (now->next)->data)
			return (FALSE);
		now = now->next;
		ptr_idx++;
	}
	return (TRUE);
}
