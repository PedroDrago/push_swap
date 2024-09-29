#include "../includes/push_swap.h"

void	init_with_tab(t_stack *stack, char *argv[])
{
	char	**tab;
	int		size;

	tab = ft_split(argv[1], ' ');
	if (!tab)
		return ;
	size = 0;
	while (tab[size])
		size++;
	while (--size >= 0)
		push(stack, new_node(ft_atoi(tab[size])));
	free_tab(tab);
}

void	init_stacks(t_stack *a, t_stack *b, int argc, char *argv[])
{
	a->top = NULL;
	a->bottom = NULL;
	b->top = NULL;
	b->bottom = NULL;
	if (argc == 2)
		init_with_tab(a, argv);
	else
		while (--argc > 0)
			push(a, new_node(ft_atoi(argv[argc])));
}
