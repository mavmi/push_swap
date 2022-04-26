#include "stack.h"

static void	print_op(char *op, char *name)
{
	ft_putstr_fd(op, 1);
	ft_putendl_fd(name, 1);
}

void	swap(t_stack *stack, char *name)
{
	int		tmp;
	t_elem	*front;
	t_elem	*second;

	if (stack->size < 2)
		return ;
	front = stack->top;
	second = front->prev;
	tmp = front->val;
	front->val = second->val;
	second->val = tmp;
	if (name)
		print_op("s", name);
}

int	push(t_stack *a, t_stack *b, char *name)
{
	if (!b->size)
		return (0);
	if (push_front(a, b->top->val))
		return (1);
	pop_front(b);
	if (name)
		print_op("p", name);
	return (0);
}

void	rotate(t_stack *stack, char *name)
{
	t_elem	*movable;

	if (stack->size < 2)
		return ;
	movable = stack->top;
	movable->next = stack->bottom;
	stack->bottom->prev = movable;
	stack->bottom = movable;
	stack->top = stack->top->prev;
	stack->top->next = NULL;
	movable->prev = NULL;
	if (name)
		print_op("r", name);
}

void	reverse_rotate(t_stack *stack, char *name)
{
	t_elem	*movable;

	if (stack->size < 2)
		return ;
	movable = stack->bottom;
	stack->bottom = stack->bottom->next;
	stack->bottom->prev = NULL;
	stack->top->next = movable;
	movable->next = NULL;
	movable->prev = stack->top;
	stack->top = movable;
	if (name)
		print_op("rr", name);
}
