/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:05:41 by pdrago            #+#    #+#             */
/*   Updated: 2024/01/11 21:05:41 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

static int	free_all(char **input, t_stack *a, t_stack *b, int error)
{
	int	count;

	count = 0;
	while (input[count])
		free(input[count++]);
	free (input);
	free_stacks(a, b);
	if (error)
		return (write(2, "Error\n", 6));
	return (0);
}

static void	check_ok(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && b->top == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

static char	**read_instructions(void)
{
	char	**instructions;
	char	*str;
	char	*gnl;

	str = (char *) ft_calloc(1, 1);
	if (!str)
		return (NULL);
	gnl = get_next_line(0);
	while (gnl)
	{
		str = ft_strjoinfree(str, gnl);
		free (gnl);
		gnl = get_next_line(0);
	}
	free (gnl);
	instructions = ft_split(str, '\n');
	free (str);
	if (!instructions)
		return (NULL);
	return (instructions);
}

static void	order(char **input, t_stack *a, t_stack *b)
{
	int	count;

	count = 0;
	while (input[count])
	{
		if (!instruction_checker(input[count++], a, b))
			exit (free_all(input, a, b, TRUE));
	}
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;
	char	**instructions;

	if (!validate(argc, argv))
		return (write(2, "Error\n", 6));
	instructions = read_instructions();
	if (!instructions)
		exit (1);
	init_stacks(&a, &b, argc, argv);
	order(instructions, &a, &b);
	check_ok(&a, &b);
	free_all(instructions, &a, &b, FALSE);
	return (0);
}
