/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:10:58 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/29 16:13:14 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error_operation(t_stack *stack_a, t_stack *stack_b, char *operation)
{
	free (operation);
	free_stack_exit(stack_a, -1, 0);
	free_stack_exit(stack_b, 0, 1);
}

void	execute_operation(t_stack *stack_a, t_stack *stack_b, char *operation)
{
	if (!ft_strncmp(operation, "ss\n", 3))
		make_swap_both(stack_a, stack_b);
	else if (!ft_strncmp(operation, "sa\n", 3))
		make_swap(stack_a);
	else if (!ft_strncmp(operation, "sb\n", 3))
		make_swap(stack_b);
	else if (!ft_strncmp(operation, "pa\n", 3))
		make_push(stack_b, stack_a);
	else if (!ft_strncmp(operation, "pb\n", 3))
		make_push(stack_a, stack_b);
	else if (!ft_strncmp(operation, "ra\n", 3))
		make_rotate(stack_a);
	else if (!ft_strncmp(operation, "rb\n", 3))
		make_rotate(stack_b);
	else if (!ft_strncmp(operation, "rr\n", 3))
		make_rotate_both(stack_a, stack_b);
	else if (!ft_strncmp(operation, "rra\n", 4))
		make_reverse(stack_a);
	else if (!ft_strncmp(operation, "rrb\n", 4))
		make_reverse(stack_b);
	else if (!ft_strncmp(operation, "rrr\n", 4))
		make_reverse_both(stack_a, stack_b);
	else
		error_operation(stack_a, stack_b, operation);
}

void	read_operation(t_stack *stack_a, t_stack *stack_b)
{
	char	*operation;

	while (1)
	{
		operation = get_next_line(STDIN_FILENO);
		if (!operation)
			break ;
		execute_operation(stack_a, stack_b, operation);
		free(operation);
	}
}

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
	read_operation(stack_a, stack_b);
	if (check_sort_stack(stack_a))
		ft_printf("Error\n");
	else if (stack_b->size)
		ft_printf("Error\n");
	else
		ft_printf("OK\n");
	free_stack_exit(stack_a, -1, 0);
	free_stack_exit(stack_b, -1, 0);
	return (0);
}
