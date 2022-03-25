/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:21:16 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/24 23:33:51 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = validation(argc, argv);
	stack_b = init_stack('b');
	if (!stack_b)
		exit_error(EXIT_FAILURE, 1);
	if (stack_a->size > 1)
	{
		if (stack_a->size == 2)
			make_swap(stack_a);
		else
			sort(stack_a, stack_b);
	}
	free_stack_exit(stack_a, -1, 0);
	free_stack_exit(stack_b, -1, 0);
	return (0);
}
