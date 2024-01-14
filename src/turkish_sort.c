/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:04:47 by pdrago            #+#    #+#             */
/*   Updated: 2024/01/11 21:04:47 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	lift_min(t_stack *stack)
{
	t_node	*min;

	if (!stack)
		return ;
	min = find_min(stack);
	while (stack->top != min)
	{
		if (min->above_median)
			ra(stack, TRUE);
		else
			rra(stack, TRUE);
	}
}

void	turkish_sort(t_stack *a, t_stack *b)
{
	int	size;

	size = stack_len(a);
	if (size-- > 3 && !is_sorted(a))
		pb(a, b, TRUE);
	if (size-- > 3 && !is_sorted(a))
		pb(a, b, TRUE);
	while (size-- > 3 && !is_sorted(a))
	{
		set_a(a, b);
		move_a_to_b(a, b);
	}
	small_sort(a);
	while (b->top)
	{
		set_b(a, b);
		move_b_to_a(a, b);
	}
	set_index_and_median(a);
	lift_min(a);
}
