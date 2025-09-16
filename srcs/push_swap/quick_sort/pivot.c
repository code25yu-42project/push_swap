#include "push_swap.h"

void	ft_pivot(int size, int *pivot1, int *pivot2, char stack)
{
	*pivot2 = size / 3 * 2;
	*pivot1 = size / 3;
	if (stack == 'a')
	{	
		if (size % 3 == 1 || size % 3 == 2)
			(*pivot2)++;
		if (size % 3 == 1)
			(*pivot1)++;
	}
	else if (stack == 'b' && size % 3 == 2)
	{
		(*pivot2) += 2;
		(*pivot1)++;
	}	
}
