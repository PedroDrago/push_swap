/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:04:51 by pdrago            #+#    #+#             */
/*   Updated: 2024/01/11 21:04:51 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*find_max(t_stack *stack)
{
	t_node	*current;
	t_node	*max;

	if (!stack)
		return (NULL);
	current = stack->top;
	max = current;
	while (current->next)
	{
		if (current->next->number > max->number)
			max = current->next;
		current = current->next;
	}
	return (max);
}

t_node	*find_min(t_stack *stack)
{
	t_node	*current;
	t_node	*min;

	if (!stack)
		return (NULL);
	current = stack->top;
	min = current;
	while (current->next)
	{
		if (current->next->number < min->number)
			min = current->next;
		current = current->next;
	}
	return (min);
}

int	stack_len(t_stack *stack)
{
	int		len;
	t_node	*current;

	len = 0;
	if (!stack || !stack->top)
		return (len);
	current = stack->top;
	while (current)
	{
		len++;
		current = current->next;
	}
	return (len);
}
