/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 00:43:47 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/20 06:29:29 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	printf("---STACK---\n");
	return (stack);
}
