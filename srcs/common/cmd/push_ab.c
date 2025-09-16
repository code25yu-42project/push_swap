#include "common.h"

int	ft_pa(t_stacklst **stacklst, t_stack **pop)
{
	t_stack		*now;
	int			full_chk;
	int			empty_chk;

	if (pop == NULL)
	{	
		pop = &now;
		empty_chk = ft_pop_head(&((*stacklst)->head_b), pop, \
										&((*stacklst)->size_b));
		if (empty_chk == 0)
			return (0);
	}
	full_chk = ft_push_head(stacklst, pop, 'a');
	if (full_chk == 0)
		return (0);
	if ((*stacklst)->print_set)
		(*stacklst)->cmd[((*stacklst)->cmd_idx)++] = PA;
	return (1);
}

int	ft_pb(t_stacklst **stacklst, t_stack **pop)
{
	t_stack		*now;
	int			full_chk;
	int			empty_chk;

	now = NULL;
	if (pop == NULL)
	{	
		pop = &now;
		empty_chk = ft_pop_head(&((*stacklst)->head_a), pop, \
										&((*stacklst)->size_a));
		if (empty_chk == 0)
			return (0);
	}
	full_chk = ft_push_head(stacklst, pop, 'b');
	if (full_chk == 0)
		return (0);
	if ((*stacklst)->print_set)
		(*stacklst)->cmd[((*stacklst)->cmd_idx)++] = PB;
	return (1);
}
