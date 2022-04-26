#include "push_swap.h"

static void	sort_3(t_stack *a)
{
	if (is_sorted(a))
		return ;
	if (get(a, 2)->val > get(a, 1)->val && get(a, 1)->val > get(a, 0)->val
		&& get(a, 0)->val < get(a, 2)->val)
	{
		swap(a, "a");
		reverse_rotate(a, "a");
	}
	else if (get(a, 2)->val < get(a, 1)->val && get(a, 1)->val > get(a, 0)->val
		&& get(a, 0)->val < get(a, 2)->val)
		reverse_rotate(a, "a");
	else if (get(a, 2)->val > get(a, 1)->val && get(a, 1)->val < get(a, 0)->val
		&& get(a, 0)->val < get(a, 2)->val)
		rotate(a, "a");
	else if (get(a, 2)->val < get(a, 1)->val && get(a, 1)->val > get(a, 0)->val
		&& get(a, 0)->val > get(a, 2)->val)
	{
		swap(a, "a");
		rotate(a, "a");
	}
	else
		swap(a, "a");
}

static int	sort_4(t_stack *a)
{
	size_t	i;
	size_t	min_pos;
	t_stack	*b;

	b = init_stack();
	if (!b)
		return (destroy_stacks(a, b));
	min_pos = 0;
	i = 1;
	while (i < a->size)
		if (get(a, i++)->val < get(a, min_pos)->val)
			min_pos = i - 1;
	i = 0;
	if (a->size - 1 - min_pos < min_pos + 1)
		while (i++ < a->size - 1 - min_pos)
			rotate(a, "a");
	else
		while (i++ < min_pos + 1)
			reverse_rotate(a, "a");
	if (push(b, a, "b"))
		return (destroy_stacks(a, b));
	sort_3(a);
	if (push(a, b, "a"))
		return (destroy_stacks(a, b));
	return (destroy_stack(b));
}

static int	sort_5(t_stack *a)
{
	size_t	i;
	size_t	min_pos;
	t_stack	*b;

	b = init_stack();
	if (!b)
		return (destroy_stacks(a, b));
	min_pos = 0;
	i = 1;
	while (i < a->size)
		if (get(a, i++)->val < get(a, min_pos)->val)
			min_pos = i - 1;
	i = 0;
	if (a->size - 1 - min_pos < min_pos + 1)
		while (i++ < a->size - 1 - min_pos)
			rotate(a, "a");
	else
		while (i++ < min_pos + 1)
			reverse_rotate(a, "a");
	if (push(b, a, "b"))
		return (destroy_stacks(a, b));
	sort_4(a);
	if (push(a, b, "a"))
		return (destroy_stacks(a, b));
	return (destroy_stack(b));
}

int	small_sort(t_stack *a, t_stack *b)
{
	int	sorted;

	sorted = is_sorted(a);
	if (a->size == 2 && !sorted)
		swap(a, "a");
	else if (a->size == 3 && !sorted)
		sort_3(a);
	else if (a->size == 4 && !sorted)
	{
		if (sort_4(a))
			return (1);
	}
	else if (a->size == 5 && !sorted)
	{
		if (sort_5(a))
			return (1);
	}
	destroy_stacks(a, b);
	return (1);
}
