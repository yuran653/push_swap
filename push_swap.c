/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:21:16 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/28 21:33:40 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	stop;
	int				stop_a;
	int				stop_b;
	t_elem			*tmp_a;
	t_elem			*tmp_b;

	tmp_a = stack_a->head;
	tmp_b = stack_b->head;
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
				printf("\t\t[%d]", tmp_a->number);
			else
				printf("\t\t[EMPTY]");
			if (stack_a->size > 1)
				tmp_a = tmp_a->next;
			if (stop_b > 0)
				printf("\t\t\t[%d]\n", tmp_b->number);
			else
				printf("\t\t\t[EMPTY]\n");
			if (stack_b->size > 1)
				tmp_b = tmp_b->next;
			stop_a--;
			stop_b--;
		}
	if (stack_a->size)
		printf("\n\tHEAD\t[%d]\t", stack_a->head->number);
	else
		printf("\n\tHEAD\t[EMPTY]");
	if (stack_b->size)
		printf("\tHEAD\t[%d]", stack_b->head->number);
	else
		printf("\tHEAD\t[EMPTY]");
	printf("\n\t--------------------\t--------------------\n\n\n\n");
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	
	if (argc == 1)
		return (0);
	stack_a = validation(argc, argv);
	stack_b = init_stack('b');
	if (!stack_b)
		error(EXIT_FAILURE);
	print_stacks(stack_a, stack_b);
	sort(stack_a, stack_b);
	// make_push(stack_a, stack_b);
	// print_stacks(stack_a, stack_b);
	// make_push(stack_a, stack_b);
	// print_stacks(stack_a, stack_b);
	// make_push(stack_a, stack_b);
	// print_stacks(stack_a, stack_b);
	// make_push(stack_a, stack_b);
	// print_stacks(stack_a, stack_b);
	// make_swap(stack_a);
	// print_stacks(stack_a, stack_b);
	// make_swap(stack_b);
	// print_stacks(stack_a, stack_b);
	// make_swap_both(stack_a, stack_b);
	// print_stacks(stack_a, stack_b);
	// make_rotate(stack_a);
	// print_stacks(stack_a, stack_b);
	// make_rotate(stack_b);
	// print_stacks(stack_a, stack_b);
	// make_rotate_both(stack_a, stack_b);
	// print_stacks(stack_a, stack_b);
	// make_reverse(stack_a);
	// print_stacks(stack_a, stack_b);
	// make_reverse(stack_b);
	// print_stacks(stack_a, stack_b);
	// make_reverse_both(stack_a, stack_b);
	// print_stacks(stack_a, stack_b);
	// make_push(stack_b, stack_a);
	// print_stacks(stack_a, stack_b);
	// make_push(stack_b, stack_a);
	// print_stacks(stack_a, stack_b);
	// make_push(stack_b, stack_a);
	// print_stacks(stack_a, stack_b);
	// make_push(stack_b, stack_a);
	// print_stacks(stack_a, stack_b);
	if (check_sort(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	print_stacks(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
