/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 00:43:47 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/24 20:35:13 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack *stack, int *unsort, int *sort)
{
	int	index;
	int	i;
	int	j;

	i = -1;
	while (++i < (int)stack->size)
	{
		j = -1;
		while (++j < (int)stack->size)
			if (unsort[i] == sort[j])
				index = j + 1;
		append_stack(stack, (init_element(unsort[i], index)));
	}
	free_array2_exit(unsort, sort, -1, 0);
}

void	append_stack(t_stack *stack, t_elem *elem)
{
	t_elem	*tmp;

	tmp = stack->head;
	if (tmp)
	{
		if (tmp->prev)
		{
			elem->next = tmp;
			elem->prev = tmp->prev;
			tmp->prev->next = elem;
			tmp->prev = elem;
		}
		else
		{
			elem->next = tmp;
			elem->prev = tmp;
			tmp->next = elem;
			tmp->prev = elem;
		}
	}
	else
		stack->head = elem;
}

t_elem	*init_element(int number, int index)
{
	t_elem	*element;

	element = (t_elem *)malloc(sizeof(t_elem));
	if (!element)
		return (NULL);
	element->number = number;
	element->index = index;
	element->order = 0;
	element->min_of_max = 0;
	element->moves = -1;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

t_stack	*init_stack(char name)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	stack->min = 0;
	stack->mid = 0;
	stack->max = 0;
	stack->total = 0;
	stack->name = name;
	return (stack);
}
