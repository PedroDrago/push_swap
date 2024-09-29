#include "../includes/push_swap.h"

void	sa(t_stack *a, int print)
{
	t_node	*node1;
	t_node	*node2;

	if (!a || !a->top || !a->top->next)
		return ;
	node1 = pop(a);
	node2 = pop(a);
	push(a, node1);
	push(a, node2);
	if (print)
		ft_printf("sa\n");
}

void	pa(t_stack *a, t_stack *b, int print)
{
	if (!a || !b || !b->top)
		return ;
	push(a, pop(b));
	if (print)
		ft_printf("pa\n");
}

void	ra(t_stack *a, int print)
{
	t_node	*tmp;

	if (!a || a->top == NULL || a->top->next == NULL)
		return ;
	tmp = pop(a);
	push_to_bottom(a, tmp);
	if (print)
		ft_printf("ra\n");
}

void	rra(t_stack *a, int print)
{
	if (!a || !a->top || !a->top->next)
		return ;
	push(a, pop_from_bottom(a));
	if (print)
		ft_printf("rra\n");
}
