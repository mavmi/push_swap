#include "push_swap.h"

size_t	rotate_b(t_stack *b, size_t min_pos)
{
	size_t	i;

	i = 0;
	if (b->size - 1 - min_pos < min_pos + 1)
	{
		while (i < b->size - 1 - min_pos)
		{
			rotate(b, "b");
			i++;
		}
	}
	else
	{
		while (i < min_pos + 1)
		{
			reverse_rotate(b, "b");
			i++;
		}
	}
	return (b->size - 1);
}

void	rotate_a(t_stack *a, size_t insert_position)
{
	size_t	i;

	i = 0;
	if (a->size - 1 - insert_position < insert_position + 1)
	{
		while (i++ < a->size - 1 - insert_position)
			rotate(a, "a");
	}
	else
	{
		while (i++ < insert_position + 1)
			reverse_rotate(a, "a");
	}
}
