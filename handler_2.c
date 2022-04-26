#include "push_swap.h"

void	parallel_rotate(t_stack *a, t_stack *b, t_elem *b_min)
{
	char	*stack_name;
	size_t	i;
	t_stack	*stack_to_move;

	i = 0;
	while (i++ < min(b_min->op_cnt[0], b_min->op_cnt[1]))
		r_rotate(a, b);
	if (b_min->op_cnt[0] > b_min->op_cnt[1])
	{
		stack_to_move = b;
		stack_name = "b";
	}
	else
	{
		stack_to_move = a;
		stack_name = "a";
	}
	i--;
	while (i++ < max(b_min->op_cnt[0], b_min->op_cnt[1]))
		rotate(stack_to_move, stack_name);
}

void	parallel_rev_rotate(t_stack *a, t_stack *b, t_elem *b_min)
{
	char	*stack_name;
	size_t	i;
	t_stack	*stack_to_move;

	i = 0;
	while (i++ < min(b_min->op_cnt[0], b_min->op_cnt[1]))
		r_reverse_rotate(a, b);
	if (b_min->op_cnt[0] > b_min->op_cnt[1])
	{
		stack_to_move = b;
		stack_name = "b";
	}
	else
	{
		stack_to_move = a;
		stack_name = "a";
	}
	i--;
	while (i++ < max(b_min->op_cnt[0], b_min->op_cnt[1]))
		reverse_rotate(stack_to_move, stack_name);
}
