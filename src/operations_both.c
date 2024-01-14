/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:04:24 by pdrago            #+#    #+#             */
/*   Updated: 2024/01/11 21:04:25 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrr(t_stack *a, t_stack *b, int print)
{
	rra(a, FALSE);
	rrb(b, FALSE);
	if (print)
		ft_printf("rrr\n");
}

void	rr(t_stack *a, t_stack *b, int print)
{
	ra(a, FALSE);
	rb(b, FALSE);
	if (print)
		ft_printf("rr\n");
}

void	ss(t_stack *a, t_stack *b, int print)
{
	sa(a, FALSE);
	sb(b, FALSE);
	if (print)
		ft_printf("ss\n");
}
