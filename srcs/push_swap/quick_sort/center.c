#include "push_swap.h"

void	ft_quick_sort(t_stacklst **stacklst, int n)
{
	if ((*stacklst)->size_data == 2)
		ft_print_cmd_two_arg(stacklst);
	else if ((*stacklst)->size_data == 3)
		ft_print_cmd_three_arg(stacklst);
	else
		ft_qs_stacka(stacklst, 0, n - 1);
	ft_print_cmd(stacklst);
}
