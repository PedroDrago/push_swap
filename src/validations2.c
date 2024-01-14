/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:04:58 by pdrago            #+#    #+#             */
/*   Updated: 2024/01/11 21:04:58 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	iterate_integers(long *vec, int size)
{
	int	count;
	int	count2;

	count = 0;
	while (count < size)
	{
		count2 = 0;
		if (vec[count] > INT_MAX || vec[count] < INT_MIN)
			return (FALSE);
		while (count2 < size)
		{
			if (count == count2)
			{
				count2++;
				if (count2 >= size)
					return (TRUE);
			}
			if (vec[count] == vec[count2])
				return (FALSE);
			count2++;
		}
		count++;
	}
	free (vec);
	return (TRUE);
}

int	validate_integers(char *tab[], int count)
{
	long	*vec;
	int		size;
	int		tmp_count;
	int		count2;

	size = 0;
	tmp_count = count;
	while (tab[tmp_count++])
		size++;
	vec = (long *) malloc (sizeof(long) * size);
	if (!vec)
		return (FALSE);
	count2 = 0;
	while (tab[count])
	{
		vec[count2] = ft_atol(tab[count]);
		count2++;
		count++;
	}
	return (iterate_integers(vec, size));
}
