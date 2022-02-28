/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 03:20:44 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/25 06:57:36 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_empty_stack(t_stack *stack_dst, t_elem *elem)
{
	stack_dst->head = elem;
	stack_dst->head->next = NULL;
	stack_dst->head->prev = NULL;
}

static void	add_two_elem_stack(t_stack *stack_dst, t_elem *elem)
{
	elem->next = stack_dst->head;
	elem->prev = stack_dst->head;
	stack_dst->head->next = elem;
	stack_dst->head->prev = elem;
	stack_dst->head = elem;
}

static void	add_multi_elem_stack(t_stack *stack_dst, t_elem *elem)
{
	elem->next = stack_dst->head;
	elem->prev = stack_dst->head->prev;
	stack_dst->head->prev->next = elem;
	stack_dst->head->prev = elem;
	stack_dst->head = elem;
}

void	add_stack(t_stack *stack_dst, t_elem *elem)
{
	if (stack_dst->head)
	{
		if (stack_dst->head->prev)
			add_multi_elem_stack(stack_dst, elem);
		else
			add_two_elem_stack(stack_dst, elem);
	}
	else
		add_empty_stack(stack_dst, elem);
	stack_dst->size++;
}

void	make_push(t_stack *stack_src, t_stack *stack_dst)
{
	t_elem	*elem;

	elem = stack_src->head;
	if (elem)
	{
		if (!elem->next)
			stack_src->head = NULL;
		else if (elem->next == elem->prev)
		{
			stack_src->head = elem->next;
			stack_src->head->next = NULL;
			stack_src->head->prev = NULL;
		}
		else
		{
			stack_src->head->prev->next = elem->next;
			stack_src->head->next->prev = elem->prev;
			stack_src->head = elem->next;
		}
		stack_src->size--;
		add_stack(stack_dst, elem);
		ft_printf("p%c\n", stack_dst->name);
	}
}
