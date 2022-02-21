/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:21:16 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/21 18:27:10 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stack(t_stack *stack)
{
	unsigned int	stop;
	
	stop = stack->size;
	if (stop)
	{
		while (stop--)
		{
			printf("\t\t[%d]\n", stack->head->number);
			if (stack->size > 1)
				stack->head = stack->head->next;
		}
	if (stack->size)
			printf("\n\tHEAD\t[%d]\n", stack->head->number);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	
	if (argc == 1)
		return (0);
	stack_a = validation(argc, argv);
	stack_b = init_stack();
	if (!stack_b)
		error();
	print_stack(stack_a);
	// make_sa(stacks, 0);
	// print_stacks(stacks);
	// make_sb(stacks, 0);
	// print_stacks(stacks);
	// make_ss(stacks);
	// print_stacks(stacks);
	// make_ra(stacks, 0);
	// print_stacks(stacks);
	// make_rb(stacks, 0);
	// print_stacks(stacks);
	// make_rr(stacks);
	// print_stacks(stacks);
	// make_rra(stacks, 0);
	// print_stacks(stacks);
	// make_rrb(stacks, 0);
	// print_stacks(stacks);
	// make_rrr(stacks);
	// print_stacks(stacks);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
