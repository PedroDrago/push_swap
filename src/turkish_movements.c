/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:04:43 by pdrago            #+#    #+#             */
/*   Updated: 2024/01/11 21:04:43 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_both(t_stack *a, t_stack *b, t_node *cheapest)
{
	while (a->top != cheapest && b->top != cheapest->target)
		rr(a, b, TRUE);
	set_index_and_median(a);
	set_index_and_median(b);
}

void	reverse_rotate_both(t_stack *a, t_stack *b, t_node *cheapest)
{
	while (a->top != cheapest && b->top != cheapest->target)
		rrr(a, b, TRUE);
	set_index_and_median(a);
	set_index_and_median(b);
}

void	move_a_to_b(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	if (!a || !b || !a->top || !b->top)
		return ;
	cheapest = get_cheapest(a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		reverse_rotate_both(a, b, cheapest);
	while (a->top != cheapest)
	{
		if (cheapest->above_median)
			ra(a, TRUE);
		else
			rra(a, TRUE);
	}
	while (b->top != cheapest->target)
	{
		if (cheapest->target->above_median)
			rb(b, TRUE);
		else
			rrb(b, TRUE);
	}
	pb(a, b, TRUE);
}

void	lift_target(t_stack *a, t_stack *b)
{
	while (a->top != b->top->target)
	{
		if (b->top->target->above_median)
			ra(a, TRUE);
		else
			rra(a, TRUE);
	}
}

void	move_b_to_a(t_stack *a, t_stack *b)
{
	if (!a || !b || !a->top || !b->top)
		return ;
	lift_target(a, b);
	pa(a, b, TRUE);
}
