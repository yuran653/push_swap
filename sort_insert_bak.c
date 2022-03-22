/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert_bak.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 23:01:55 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/22 23:42:49 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_two_top(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	h;
	int	n;

	h = stack_b->head->index;
	n = stack_b->head->next->index;
	while (stack_b->head->index != value - 1)
		make_rotate(stack_b);
	make_push(stack_b, stack_a);
	while (stack_b->head->index != value)
		make_rotate(stack_b);
	make_push(stack_b, stack_a);
	if (h < n)
		make_swap_both(stack_a, stack_b);
	else
		make_swap(stack_a);
}

int	find_top(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_elem	*fix;
	int		i;
	int		is_two;

	fix = stack_b->head;
	i = stack_b->size / 2 + stack_b->size % 2;
	is_two = 0;
	while (i--)
	{
		if (stack_b->head->next->index == value - 1)
			is_two++;
		if (stack_b->head->next->index == value)
		{
			stack_b->head = fix;
			if (!is_two)
				return (1);
			else
				insert_two_top(stack_a, stack_b, value);
			return (0);
		}
		stack_b->head = stack_b->head->next;
	}
	stack_b->head = fix;
	return (0);
}

static void	insert_two_btm(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	h;
	int	n;

	h = stack_b->head->index;
	n = stack_b->head->next->index;
	while (stack_b->head->index != value - 1)
		make_reverse(stack_b);
	make_push(stack_b, stack_a);
	while (stack_b->head->index != value)
		make_reverse(stack_b);
	make_push(stack_b, stack_a);
	if (h < n)
		make_swap_both(stack_a, stack_b);
	else
		make_swap(stack_a);
}

int	find_btm(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_elem	*fix;
	int		i;
	int		is_two;

	fix = stack_b->head;
	i = stack_b->size / 2;
	is_two = 0;
	while (i--)
	{
		if (stack_b->head->prev->index == value - 1)
			is_two++;
		if (stack_b->head->prev->index == value)
		{
			stack_b->head = fix;
			if (!is_two)
				return (1);
			else
				insert_two_btm(stack_a, stack_b, value);
			return (0);
		}
		stack_b->head = stack_b->head->prev;
	}
	stack_b->head = fix;
	return (0);
}

void	sort_insert(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size)
	{
		if (stack_b->head->index == stack_a->head->index - 1)
			make_push(stack_b, stack_a);
		else if (find_top(stack_a, stack_b, stack_a->head->index - 1))
		{
			while (stack_b->head->index != stack_a->head->index - 1)
				make_rotate(stack_b);
			make_push(stack_b, stack_a);
		}
		else if (find_btm(stack_a, stack_b, stack_a->head->index - 1))
		{
			while (stack_b->head->index != stack_a->head->index - 1)
				make_reverse(stack_b);
			make_push(stack_b, stack_a);
		}
	}
}
