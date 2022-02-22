/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:21:16 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/22 07:37:21 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	stop;
	int				stop_a;
	int				stop_b;

	stop_a = (int)stack_a->size;
	stop_b = (int)stack_b->size;
	if (stop_a > stop_b)
		stop = stop_a;
	else
		stop = stop_b;
	if (stop)
	{
		printf("\t-------STACK A-------\t-------STACK B-------\n");
		while (stop--)
		{
			if (stop_a > 0)
				printf("\t\t[%d]", stack_a->head->number);
			else
				printf("\t\t[EMPTY]");
			if (stack_a->size > 1)
				stack_a->head = stack_a->head->next;
			if (stop_b > 0)
				printf("\t\t\t[%d]\n", stack_b->head->number);
			else
				printf("\t\t\t[EMPTY]\n");
			if (stack_b->size > 1)
				stack_b->head = stack_b->head->next;
			stop_a--;
			stop_b--;
		}
	if (stack_a->size)
		printf("\n\tHEAD\t[%d]\t", stack_a->head->number);
	else
		printf("\n\tHEAD\t[EMPTY]");
	if (stack_b->size)
		printf("\t\tHEAD\t[%d]", stack_b->head->number);
	else
		printf("\tHEAD\t[EMPTY]");
	printf("\n\n");
	}
}

// void	print_stack(t_stack *stack)
// {
// 	unsigned int	stop;
	
// 	stop = stack->size;
// 	if (stop)
// 	{
// 		while (stop--)
// 		{
// 			printf("\t\t[%d]\n", stack->head->number);
// 			if (stack->size > 1)
// 				stack->head = stack->head->next;
// 		}
// 	if (stack->size)
// 			printf("\n\tHEAD\t[%d]\n", stack->head->number);
// 	}
// }

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	
	if (argc == 1)
		return (0);
	stack_a = validation(argc, argv);
	stack_b = init_stack('b');
	if (!stack_b)
		error();
	print_stacks(stack_a, stack_b);
	make_push(stack_a, stack_b);
	print_stacks(stack_a, stack_b);
	make_push(stack_b, stack_a);
	print_stacks(stack_a, stack_b);
	// print_stacks(stack_a, stack_b);
	// make_swap(stack_a, 'y');
	// print_stacks(stack_a, stack_b);
	// make_swap(stack_b, 'y');
	// print_stacks(stack_a, stack_b);
	// make_swap_both(stack_a, stack_b);
	// print_stacks(stack_a, stack_b);
	// make_rotate(stack_a, 'y');
	// print_stacks(stack_a, stack_b);
	// make_rotate(stack_b, 'y');
	// print_stacks(stack_a, stack_b);
	// make_rotate_both(stack_a, stack_b);
	// print_stacks(stack_a, stack_b);
	// make_reverse(stack_a, 'y');
	// print_stacks(stack_a, stack_b);
	// make_reverse(stack_b, 'y');
	// print_stacks(stack_a, stack_b);
	// make_reverse_both(stack_a, stack_b);
	// print_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
