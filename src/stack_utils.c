#include "../includes/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*current_node;

	current_node = stack->top;
	ft_printf("------------\n");
	if (current_node == NULL)
		ft_printf("(Empty Stack)\n");
	while (current_node)
	{
		ft_printf("%i\n", current_node->number);
		current_node = current_node->next;
	}
	ft_printf("------------\n\n");
}

void	test_operation(t_stack *a, t_stack *b)
{
	ft_printf("BEFORE OPERATION: \n");
	ft_printf("a:\n");
	print_stack(a);
	ft_printf("b:\n");
	print_stack(b);
	pb(a, b, FALSE);
	ft_printf("AFTER OPERATION: \n");
	ft_printf("a:\n");
	print_stack(a);
	ft_printf("b:\n");
	print_stack(b);
}

void	free_tab(char *tab[])
{
	int	count;

	count = -1;
	while (tab[++count])
		free (tab[count]);
	free (tab);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	if (!current)
		return (TRUE);
	while (current->next)
	{
		if (current->number > current->next->number)
			return (FALSE);
		current = current->next;
	}
	return (TRUE);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	if (a)
		while (a->top)
			free (pop(a));
	if (b)
		while (b->top)
			free (pop(b));
}
