#include "stack.h"

void	r_rotate(t_stack *a, t_stack *b)
{
	rotate(a, NULL);
	rotate(b, NULL);
	ft_putendl_fd("rr", 1);
}

void	r_reverse_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate(a, NULL);
	reverse_rotate(b, NULL);
	ft_putendl_fd("rrr", 1);
}
