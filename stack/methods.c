#include "stack.h"

t_elem	*get_new_elem(int value, t_elem *prev)
{
	t_elem	*new_elem;

	new_elem = (t_elem *)malloc(sizeof(t_elem));
	if (!new_elem)
		return (NULL);
	new_elem->val = value;
	new_elem->score = 0;
	new_elem->next = NULL;
	new_elem->prev = prev;
	return (new_elem);
}

void	pop_front(t_stack *stack)
{
	t_elem	*prenult;

	if (!stack || !stack->size)
		return ;
	if (stack->size == 1)
	{
		free(stack->top);
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		prenult = stack->top->prev;
		free(stack->top);
		stack->top = prenult;
		stack->top->next = NULL;
	}
	stack->size--;
}

int	push_front(t_stack *stack, int new_val)
{
	t_elem	*new_elem;

	if (!stack)
		return (1);
	if (!stack->size)
	{
		new_elem = get_new_elem(new_val, NULL);
		if (!new_elem)
			return (1);
		stack->bottom = new_elem;
		stack->top = stack->bottom;
	}
	else
	{
		new_elem = get_new_elem(new_val, stack->top);
		if (!new_elem)
			return (1);
		stack->top->next = new_elem;
		stack->top = new_elem;
	}
	stack->size++;
	return (0);
}

t_elem	*get(t_stack *stack, size_t pos)
{
	size_t	counter;
	t_elem	*ptr;

	if (!stack || stack->size == 0 || stack->size - 1 < pos)
		return (NULL);
	counter = 0;
	ptr = stack->bottom;
	while (counter < pos)
	{
		ptr = ptr->next;
		counter++;
	}
	return (ptr);
}
