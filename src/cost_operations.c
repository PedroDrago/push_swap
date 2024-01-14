/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:04:11 by pdrago            #+#    #+#             */
/*   Updated: 2024/01/11 21:04:12 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*get_cheapest(t_stack *stack)
{
	t_node	*current;

	if (!stack)
		return (NULL);
	current = stack->top;
	while (current)
	{
		if (current->cheapest)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	set_cheapest(t_stack *stack)
{
	t_node	*current;
	t_node	*cheapest_node;
	int		cheapest_value;

	if (!stack)
		return ;
	current = stack->top;
	cheapest_value = INT_MAX;
	cheapest_node = current;
	while (current->next)
	{
		if (current->cost < cheapest_value)
		{
			cheapest_value = current->cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	cheapest_node->cheapest = TRUE;
}

void	set_cost_a(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		len_a;
	int		len_b;

	if (!a || !b)
		return ;
	current = a->top;
	len_a = stack_len(a);
	len_b = stack_len(b);
	while (current)
	{
		current->cost = current->index;
		if (!current->above_median)
			current->cost = len_a - current->index;
		if (current->target->above_median)
			current->cost += current->target->index;
		else
			current->cost += len_b - current->target->index;
		current = current->next;
	}
}
