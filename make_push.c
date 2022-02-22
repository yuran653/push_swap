/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 03:20:44 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/22 07:51:52 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_stack(t_stack *stack_dst, t_elem *elem)
{
	if (!stack_dst->size)
		stack_dst->head = elem;
}

void	make_push(t_stack *stack_src, t_stack *stack_dst)
{
	t_elem	*elem;

	elem = stack_src->head;
	if (stack_src->size)
	{
		if (stack_src->size == 1)
			stack_src->head = NULL;
		else
		{
			stack_src->head->prev->next = elem->next;
			stack_src->head->next->prev = elem->prev;
			stack_src->head = elem->next;
		}
		add_stack(stack_dst, elem);
		stack_dst->size++;
		stack_src->size--;
	}
	ft_printf("p%c\n", stack_dst->name);
}