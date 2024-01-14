/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:06:35 by pdrago            #+#    #+#             */
/*   Updated: 2024/01/11 21:06:36 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_node
{
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*previous;
	int				number;
	int				cost;
	int				above_median;
	int				cheapest;
	int				index;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
}	t_stack;

int		validate(int argc, char *argv[]);
int		validate_tab(char *tab[], int is_argv);
int		check_invalid_characters(char *tab[], int count);
int		check_invalid_minus(char *tab[], int is_argv);
int		iterate_integers(long *vec, int size);
int		validate_integers(char *tab[], int count);
int		is_sorted(t_stack *stack);
int		stack_len(t_stack *stack);
void	lift_min(t_stack *stack);
void	turkish_sort(t_stack *a, t_stack *b);
void	set_index_and_median(t_stack *stack);
void	set_a(t_stack *a, t_stack *b);
void	set_b(t_stack *a, t_stack *b);
void	rotate_both(t_stack *a, t_stack *b, t_node *cheapest);
void	reverse_rotate_both(t_stack *a, t_stack *b, t_node *cheapest);
void	move_a_to_b(t_stack *a, t_stack *b);
void	lift_target(t_stack *a, t_stack *b);
void	move_b_to_a(t_stack *a, t_stack *b);
void	set_targets_a(t_stack *a, t_stack *b);
void	set_targets_b(t_stack *a, t_stack *b);
void	init_with_tab(t_stack *stack, char *argv[]);
void	init_stacks(t_stack *a, t_stack *b, int argc, char *argv[]);
void	print_stack(t_stack *stack);
void	test_operation(t_stack *a, t_stack *b);
void	free_tab(char *tab[]);
void	free_stacks(t_stack *a, t_stack *b);
void	small_sort(t_stack *a);
void	set_cost_a(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *stack);
void	sa(t_stack *a, int print);
void	sb(t_stack *b, int print);
void	ss(t_stack *a, t_stack *b, int print);
void	pa(t_stack *a, t_stack *b, int print);
void	pb(t_stack *a, t_stack *b, int print);
void	ra(t_stack *a, int print);
void	rb(t_stack *b, int print);
void	rr(t_stack *a, t_stack *b, int print);
void	rra(t_stack *a, int print);
void	rrb(t_stack *b, int print);
void	rrr(t_stack *a, t_stack *b, int print);
void	push(t_stack *stack, t_node *node);
void	push_to_bottom(t_stack *stack, t_node *node);
t_node	*get_cheapest(t_stack *stack);
t_node	*find_min(t_stack *stack);
t_node	*find_max(t_stack *stack);
t_node	*get_cheapest(t_stack *stack);
t_node	*new_node(int number);
t_node	*pop(t_stack *stack);
t_node	*pop_from_bottom(t_stack *stack);
t_node	*find_max(t_stack *stack);
t_node	*find_min(t_stack *stack);
#endif
