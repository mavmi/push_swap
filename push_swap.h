#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack/stack.h"
# include "input_handler/input_handler.h"

size_t	rotate_b(t_stack *b, size_t min_pos);
void	rotate_a(t_stack *a, size_t insert_position);
void	parallel_rotate(t_stack *a, t_stack *b, t_elem *b_min);
void	parallel_rev_rotate(t_stack *a, t_stack *b, t_elem *b_min);

void	set_up_scores(t_stack *a, t_stack *b);
int		small_sort(t_stack *a, t_stack *b);

int		min_element(t_stack *stack);
int		max_element(t_stack *stack);
t_elem	*get_min_score_elem(t_stack *stack);
size_t	get_ins_pos(t_stack *a, int b_min_val);
size_t	get_min_pos(t_stack *b);
int		is_sorted(t_stack *stack);

void	exit_with_error(int *nums);
int		destroy_stacks(t_stack *a, t_stack *b);
size_t	min(size_t a, size_t b);
size_t	max(size_t a, size_t b);

#endif
