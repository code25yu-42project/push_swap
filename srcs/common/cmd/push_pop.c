#include "common.h"

int	ft_push_deq(t_stack **push_stack, t_stack **pop, int *push_size)
{
	if (*push_size == 0)
	{
		*push_stack = *pop;
		(*push_stack)->pre = NULL;
		(*push_stack)->next = *pop;
	}
	else
	{
		if (*push_size == 1)
		{
			(*pop)->pre = (*push_stack);
			(*push_stack)->next = *pop;
		}
		else
			(*pop)->pre = (*push_stack)->pre;
		(*pop)->next = (*push_stack);
		if ((*push_stack)->pre != NULL)
			(*push_stack)->pre->next = *pop;
		(*push_stack)->pre = *pop;
		*push_stack = *pop;
	}
	(*push_size)++;
	return (1);
}

int	ft_push_head(t_stacklst **stacklst, t_stack **pop, char push_stackname)
{
	int	*stack_size;

	if (push_stackname == 'a')
		stack_size = &((*stacklst)->size_a);
	else
	{
		if ((*stacklst)->head_b == NULL)
			(*stacklst)->size_b = 0;
		stack_size = &((*stacklst)->size_b);
	}
	if (ft_isfull((*stacklst)->size_data, *stack_size) == TRUE)
		return (0);
	if (push_stackname == 'a')
		ft_push_deq(&((*stacklst)->head_a), pop, stack_size);
	else
		ft_push_deq(&((*stacklst)->head_b), pop, stack_size);
	return (1);
}

void	ft_pop_deq(t_stack **pop_stack, t_stack **pop, int *pop_size)
{
	if (*pop_size == 0)
	{
		*pop_stack = NULL;
		*pop = *pop_stack;
	}
	else
	{
		if ((*pop_stack)->pre && (*pop_stack)->next)
		{	
			(*pop_stack)->pre->next = (*pop_stack)->next;
			(*pop_stack)->next->pre = (*pop_stack)->pre;
		}
		*pop = *pop_stack;
		if (*pop_stack == (*pop_stack)->next)
			*pop_stack = NULL;
		else
			*pop_stack = (*pop_stack)->next;
	}
	(*pop_size)--;
}

int	ft_pop_head(t_stack **pop_stack, t_stack **pop, int *pop_size)
{
	if (ft_isempty(*pop_stack) == TRUE)
		return (0);
	ft_pop_deq(pop_stack, pop, pop_size);
	return (1);
}
