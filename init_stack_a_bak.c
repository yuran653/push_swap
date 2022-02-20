/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a_bak.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 00:43:47 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/20 04:14:42 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_stacks *stacks, t_elem *element)
{
	t_elem	*tmp;

	tmp = stacks->head_a;
	if (tmp)
	{
		if (tmp->prev)
		{
			element->next = tmp;
			element->prev = tmp->prev;
			tmp->prev->next = element;
			tmp->prev = element;
		}
		else
		{
			element->next = tmp;
			element->prev = tmp;
			tmp->next = element;
			tmp->prev = element;
		}
	}
	else
		stacks->head_a = element;
}

t_elem	*init_element(int number)
{
	t_elem	*element;

	element = (t_elem *)malloc(sizeof(t_elem));
	if (!element)
		return (NULL);
	element->number = number;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

t_stacks	*init_stacks(void)
{
	t_stacks	*stacks;

	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->head_a = NULL;
	stacks->head_b = NULL;
	stacks->size_a = 0;
	stacks->size_b = 0;
	return (stacks);
}
