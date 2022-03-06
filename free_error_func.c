/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:22:18 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/06 18:20:31 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(int ext, int err)
{
	if (err)
		ft_putstr_fd("Error\n", STDERR_FILENO);
	if (ext == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	if (ext == EXIT_SUCCESS)
		exit(EXIT_SUCCESS);
}

void	free_array2_exit(int *array1, int *array2, int ext, int err)
{
	free(array1);
	free(array2);
	exit_error(ext, err);
}

void	free_array_exit(int *array, int ext, int err)
{
	free(array);
	exit_error(ext, err);
}

void	free_argv_exit(int argc, char **argv, int ext, int err)
{
	int	i;

	i = -1;
	if (argc == 2)
	{
		while (argv[++i])
			free(argv[i]);
		free(argv);
	}
	exit_error(ext, err);
}

void	free_stack_exit(t_stack *stack, int ext, int err)
{
	t_elem			*tmp;

	if (stack->head && stack->size > 1)
		stack->head->prev->next = NULL;
	while (stack->head)
	{
		tmp = stack->head->next;
		free(stack->head);
		stack->head = tmp;
	}
	free(stack);
	exit_error(ext, err);
}
