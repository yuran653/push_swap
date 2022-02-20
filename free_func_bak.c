/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func_bak.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:22:18 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/20 05:56:14 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

void	free_stacks(t_stacks *stacks)
{
	t_elem			*tmp;
	unsigned int	size_a;
	unsigned int	size_b;

	size_a = stacks->size_a;
	size_b = stacks->size_b;
	while (size_a--)
	{
		tmp = stacks->head_a->next;
		free(stacks->head_a);
		if (tmp)
			stacks->head_a = tmp;
	}
	while (size_b--)
	{
		tmp = stacks->head_b->next;
		free(stacks->head_b);
		if (tmp)
			stacks->head_b = tmp;
	}
	free(stacks);
}