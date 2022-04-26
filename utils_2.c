#include "push_swap.h"

void	exit_with_error(int *nums)
{
	free(nums);
	ft_putendl_fd("Error", 1);
	exit(1);
}

int	destroy_stacks(t_stack *a, t_stack *b)
{
	destroy_stack(a);
	destroy_stack(b);
	return (1);
}

size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

int	is_sorted(t_stack *stack)
{
	t_elem	*ptr;

	if (!stack)
		return (-1);
	if (stack->size <= 1)
		return (1);
	ptr = stack->bottom->next;
	while (ptr)
	{
		if (ptr->val > ptr->prev->val)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
