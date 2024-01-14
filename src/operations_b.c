/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:04:20 by pdrago            #+#    #+#             */
/*   Updated: 2024/01/11 21:04:21 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_stack *a, t_stack *b, int print)
{
	if (!a || !b || !a->top)
		return ;
	push(b, pop(a));
	if (print)
		ft_printf("pb\n");
}

void	sb(t_stack *b, int print)
{
	t_node	*node1;
	t_node	*node2;

	if (!b || !b->top || !b->top->next)
		return ;
	node1 = pop(b);
	node2 = pop(b);
	push(b, node1);
	push(b, node2);
	if (print)
		ft_printf("sb\n");
}

void	rb(t_stack *b, int print)
{
	t_node	*tmp;

	if (!b || b->top == NULL || b->top->next == NULL)
		return ;
	tmp = pop(b);
	push_to_bottom(b, tmp);
	if (print)
		ft_printf("rb\n");
}

void	rrb(t_stack *b, int print)
{
	if (!b || !b->top || !b->top->next)
		return ;
	push(b, pop_from_bottom(b));
	if (print)
		ft_printf("rrb\n");
}
