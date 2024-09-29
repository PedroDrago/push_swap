#include "../includes/push_swap.h"

static int	short_a_condition(t_node *current_a,
			t_node *current_b, int current_match)
{
	return ((current_b->number < current_a->number
			&& current_b->number > current_match));
}

void	set_targets_a(t_stack *a, t_stack *b)
{
	t_node	*current_a;
	t_node	*current_b;
	t_node	*target;
	int		current_match;

	current_a = a->top;
	while (current_a)
	{
		current_match = INT_MIN;
		current_b = b->top;
		while (current_b)
		{
			if (short_a_condition(current_a, current_b, current_match))
			{
				current_match = current_b->number;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (current_match == INT_MIN)
			current_a->target = find_max(b);
		else
			current_a->target = target;
		current_a = current_a->next;
	}
}

static int	short_b_condition(t_node *current_a,
			t_node *current_b, int current_match)
{
	return ((current_a->number > current_b->number
			&& current_a->number < current_match));
}

void	set_targets_b(t_stack *a, t_stack *b)
{
	t_node	*current_a;
	t_node	*current_b;
	t_node	*target;
	int		current_match;

	current_b = b->top;
	while (current_b)
	{
		current_match = INT_MAX;
		current_a = a->top;
		while (current_a)
		{
			if (short_b_condition(current_a, current_b, current_match))
			{
				current_match = current_a->number;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (current_match == INT_MAX)
			current_b->target = find_min(a);
		else
			current_b->target = target;
		current_b = current_b->next;
	}
}
