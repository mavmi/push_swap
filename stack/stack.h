#ifndef STACK_H
# define STACK_H

# include "../libft/libft.h"
# include <stdlib.h>

# ifndef ROTATE
#  define ROTATE 1
# endif

# ifndef REV_ROTATE
#  define REV_ROTATE 2
# endif

typedef struct s_stack_elem
{
	int					val;
	size_t				score;
	size_t				opers[2];
	size_t				op_cnt[2];
	struct s_stack_elem	*next;
	struct s_stack_elem	*prev;
}						t_elem;

typedef struct s_stack
{
	t_elem	*bottom;
	t_elem	*top;
	size_t	size;
}			t_stack;

void	swap(t_stack *stack, char *name);
int		push(t_stack *a, t_stack *b, char *name);
void	rotate(t_stack *stack, char *name);
void	reverse_rotate(t_stack *stack, char *name);
void	r_rotate(t_stack *a, t_stack *b);
void	r_reverse_rotate(t_stack *a, t_stack *b);

t_stack	*init_stack(void);
int		destroy_stack(t_stack *stack);
t_elem	*get_new_elem(int value, t_elem *prev);
void	pop_front(t_stack *stack);
int		push_front(t_stack *stack, int new_val);
t_elem	*get(t_stack *stack, size_t pos);

#endif
