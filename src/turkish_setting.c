#include "../includes/push_swap.h"

void	set_index_and_median(t_stack *stack)
{
	int		index;
	int		median;
	t_node	*current;

	if (!stack)
		return ;
	current = stack->top;
	index = 0;
	median = stack_len(stack) / 2;
	while (current)
	{
		current->index = index;
		if (current->index <= median)
			current->above_median = TRUE;
		else
			current->above_median = FALSE;
		index++;
		current = current->next;
	}
}

void	set_a(t_stack *a, t_stack *b)
{
	set_index_and_median(a);
	set_index_and_median(b);
	set_targets_a(a, b);
	set_cost_a(a, b);
	set_cheapest(a);
}

void	set_b(t_stack *a, t_stack *b)
{
	set_index_and_median(a);
	set_index_and_median(b);
	set_targets_b(a, b);
}
