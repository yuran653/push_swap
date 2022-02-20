/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:22:18 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/20 06:17:42 by jgoldste         ###   ########.fr       */
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

void	free_stack(t_stack *stack)
{
	t_elem			*tmp;
	
	stack->head->prev->next = NULL;
	while (stack->head)
	{
		tmp = stack->head->next;
		free(stack->head);
		stack->head = tmp;
	}
	free(stack);
}
