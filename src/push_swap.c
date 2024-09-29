#include "../includes/push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	int	len_a;

	len_a = stack_len(a);
	if (len_a == 2)
		sa(a, TRUE);
	else if (len_a == 3)
		small_sort(a);
	else
		turkish_sort(a, b);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (!validate(argc, argv))
		return (1);
	init_stacks(&a, &b, argc, argv);
	if (!is_sorted(&a))
		push_swap(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
