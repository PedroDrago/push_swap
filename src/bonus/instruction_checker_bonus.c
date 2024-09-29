#include "../../includes/checker_bonus.h"

int	instruction_checker(char *instruction, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(instruction, "sa", 3))
		sa(a, FALSE);
	else if (!ft_strncmp(instruction, "sb", 3))
		sb(b, FALSE);
	else if (!ft_strncmp(instruction, "ss", 3))
		ss(a, b, FALSE);
	else if (!ft_strncmp(instruction, "pa", 3))
		pa(a, b, FALSE);
	else if (!ft_strncmp(instruction, "pb", 3))
		pb(a, b, FALSE);
	else if (!ft_strncmp(instruction, "ra", 3))
		ra(a, FALSE);
	else if (!ft_strncmp(instruction, "rb", 3))
		rb(b, FALSE);
	else if (!ft_strncmp(instruction, "rr", 3))
		rr(a, b, FALSE);
	else if (!ft_strncmp(instruction, "rra", 4))
		rra(a, FALSE);
	else if (!ft_strncmp(instruction, "rrb", 4))
		rrb(b, FALSE);
	else if (!ft_strncmp(instruction, "rrr", 4))
		rrr(a, b, FALSE);
	else
		return (FALSE);
	return (TRUE);
}
