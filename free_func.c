/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:22:18 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/06 02:06:28 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array_exit(int *array)
{
	free(array);
	exit(EXIT_SUCCESS);
}

void	free_argv(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc == 2)
	{
		while (argv[++i])
			free(argv[i]);
		free(argv);
	}
}

void	free_stack(t_stack *stack)
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
}
