#include "stack.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->bottom = NULL;
	stack->top = NULL;
	return (stack);
}

int	destroy_stack(t_stack *stack)
{
	t_elem	*ptr;
	t_elem	*next;

	if (!stack)
		return (0);
	ptr = stack->bottom;
	while (ptr)
	{
		next = ptr->next;
		free(ptr);
		ptr = next;
	}
	free(stack);
	return (0);
}
