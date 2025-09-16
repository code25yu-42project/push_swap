#include "push_swap.h"

int	ft_cmp_three_int(int a, int b, int c)
{
	if (a < b && b < c)
		return (123);
	if (a < c && c < b)
		return (132);
	if (b < a && a < c)
		return (213);
	if (b < c && c < a)
		return (312);
	if (c < a && a < b)
		return (231);
	if (c < b && b < a)
		return (321);
	return (0);
}
