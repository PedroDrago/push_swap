/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:04:31 by pdrago            #+#    #+#             */
/*   Updated: 2024/01/11 21:04:32 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	small_sort(t_stack *a)
{
	t_node	*max;

	max = find_max(a);
	if (a->top == max)
		ra(a, TRUE);
	else if (a->top->next == max)
		rra(a, TRUE);
	if (a->top->number > a->top->next->number)
		sa(a, TRUE);
}
