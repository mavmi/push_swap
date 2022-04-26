#include "push_swap.h"

static void	set_opers_count(t_elem *b_elem)
{
	b_elem->score = 1;
	if (b_elem->opers[0] == b_elem->opers[1])
		b_elem->score += max(b_elem->op_cnt[0], b_elem->op_cnt[1]);
	else
		b_elem->score += b_elem->op_cnt[0] + b_elem->op_cnt[1];
}

static void	set_b_opers(t_elem *b_elem, size_t pos, size_t size)
{
	if (size - pos - 1 < pos + 1)
	{
		b_elem->opers[0] = ROTATE;
		b_elem->op_cnt[0] = size - pos - 1;
	}
	else
	{
		b_elem->opers[0] = REV_ROTATE;
		b_elem->op_cnt[0] = pos + 1;
	}
	if (!b_elem->op_cnt[0])
		b_elem->opers[0] = 0;
}

static void	set_a_opers(t_elem *b_elem, size_t pos, size_t size)
{
	if (size - pos - 1 < pos + 1)
	{
		b_elem->opers[1] = ROTATE;
		b_elem->op_cnt[1] = size - pos - 1;
	}
	else
	{
		b_elem->opers[1] = REV_ROTATE;
		b_elem->op_cnt[1] = pos + 1;
	}
	if (!b_elem->op_cnt[1])
		b_elem->opers[1] = 0;
}

void	set_up_scores(t_stack *a, t_stack *b)
{
	size_t	i;
	t_elem	*b_elem;

	i = 0;
	b_elem = b->bottom;
	while (i < b->size)
	{
		set_b_opers(b_elem, i, b->size);
		set_a_opers(b_elem, get_ins_pos(a, b_elem->val), a->size);
		set_opers_count(b_elem);
		i++;
		b_elem = b_elem->next;
	}
}
