#include "../includes/push_swap.h"

t_node	*new_node(int number)
{
	t_node	*node;

	node = (t_node *) malloc (sizeof(t_node));
	if (!node)
		return (NULL);
	node->cost = 0;
	node->next = NULL;
	node->previous = NULL;
	node->cheapest = FALSE;
	node->above_median = FALSE;
	node->number = number;
	return (node);
}

void	push(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (!stack->top)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->next = stack->top;
		stack->top->previous = node;
		stack->top = node;
	}
}

void	push_to_bottom(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (!stack->top)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->previous = stack->bottom;
		stack->bottom->next = node;
		stack->bottom = node;
	}
}

t_node	*pop(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	node = stack->top;
	if (!node->next)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		node->next->previous = NULL;
		stack->top = node->next;
	}
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

t_node	*pop_from_bottom(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	node = stack->bottom;
	if (!node->previous)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		node->previous->next = NULL;
		stack->bottom = node->previous;
	}
	node->next = NULL;
	node->previous = NULL;
	return (node);
}
