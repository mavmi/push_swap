#include "push_swap.h"

int	min_element(t_stack *stack)
{
	int		min;
	t_elem	*ptr;

	if (!stack || !stack->size)
		return (0);
	ptr = stack->bottom->next;
	min = stack->bottom->val;
	while (ptr)
	{
		if (ptr->val < min)
			min = ptr->val;
		ptr = ptr->next;
	}
	return (min);
}

int	max_element(t_stack *stack)
{
	int		max;
	t_elem	*ptr;

	if (!stack || !stack->size)
		return (0);
	ptr = stack->bottom->next;
	max = stack->bottom->val;
	while (ptr)
	{
		if (ptr->val > max)
			max = ptr->val;
		ptr = ptr->next;
	}
	return (max);
}

t_elem	*get_min_score_elem(t_stack *stack)
{
	t_elem	*min;
	t_elem	*ptr;

	if (!stack || !stack->size)
		return (0);
	ptr = stack->bottom->next;
	min = stack->bottom;
	while (ptr)
	{
		if (ptr->score < min->score)
			min = ptr;
		ptr = ptr->next;
	}
	return (min);
}

size_t	get_ins_pos(t_stack *a, int b_min_val)
{
	t_elem	*a_elem;
	size_t	j;
	size_t	insert_position;

	insert_position = 0;
	if (a->bottom->val < b_min_val && a->top->val > b_min_val)
		insert_position = a->size - 1;
	else
	{
		a_elem = a->bottom->next;
		j = 1;
		while (j < a->size)
		{
			if (a_elem->val < b_min_val && a_elem->prev->val > b_min_val)
			{
				insert_position = j - 1;
				break ;
			}
			j++;
			a_elem = a_elem->next;
		}
	}
	return (insert_position);
}

size_t	get_min_pos(t_stack *b)
{
	size_t	i;
	size_t	min_pos;

	i = 1;
	min_pos = 0;
	while (i < b->size)
	{
		if (get(b, i)->score < get(b, min_pos)->score)
			min_pos = i;
		i++;
	}
	return (min_pos);
}
