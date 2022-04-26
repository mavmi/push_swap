#include "push_swap.h"

static int	create_stacks(t_stack **a, t_stack **b, int argc, char **argv)
{
	int	min;
	int	max;

	*a = input_handler(argc, argv);
	*b = init_stack();
	if (!*a || !*b)
		return (destroy_stacks(*a, *b));
	if ((*a)->size < 6 || is_sorted(*a))
		return (small_sort(*a, *b));
	min = min_element(*a);
	max = max_element(*a);
	while ((*a)->size != 2)
	{
		if ((*a)->top->val != max && (*a)->top->val != min)
		{
			if (push(*b, *a, "b"))
				return (destroy_stacks(*a, *b));
		}
		else
			rotate(*a, "a");
	}
	if ((*a)->top->val > (*a)->bottom->val)
		swap(*a, "a");
	return (0);
}

static void	set_a(t_stack *a)
{
	size_t	i;
	size_t	min_pos;

	i = 1;
	min_pos = 0;
	while (i < a->size)
	{
		if (get(a, i)->val < get(a, min_pos)->val)
			min_pos = i;
		i++;
	}
	i = 0;
	if (a->size - 1 - min_pos < min_pos + 1)
	{
		while (i++ < a->size - 1 - min_pos)
			rotate(a, "a");
	}
	else
	{
		while (i++ < min_pos + 1)
			reverse_rotate(a, "a");
	}
}

static void	call_rotates(t_stack *a, t_stack *b, t_elem *b_min)
{
	if (b_min->opers[0] == b_min->opers[1])
	{
		if (b_min->opers[0] == ROTATE)
			parallel_rotate(a, b, b_min);
		else
			parallel_rev_rotate(a, b, b_min);
	}
	else
	{
		rotate_b(b, get_min_pos(b));
		rotate_a(a, get_ins_pos(a, b_min->val));
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (create_stacks(&a, &b, argc, argv))
		return (0);
	while (b->size)
	{
		set_up_scores(a, b);
		call_rotates(a, b, get_min_score_elem(b));
		if (push(a, b, "a"))
			return (destroy_stacks(a, b));
	}
	set_a(a);
	destroy_stack(a);
	destroy_stack(b);
}
