/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:11:13 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/29 12:53:12 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	qrtr_stack_back_btm(t_stack *stack_a, t_stack *stack_b, int max_b)
{
	make_reverse(stack_a);
	set_min_mid_max(stack_a);
	while (stack_a->head->index < stack_a->min + stack_a->total / 6)
	{
		if (stack_a->head->index > max_b)
			make_reverse(stack_a);
		else
		{
			make_push(stack_a, stack_b);
			make_reverse(stack_a);
			if (stack_b->head->index > stack_a->min + stack_a->total / 16)
				make_rotate(stack_b);
		}
	}
}

static void	qrtr_stack_back_top(t_stack *stack_a, t_stack *stack_b, int max_b)
{
	set_min_mid_max(stack_a);
	while (stack_a->head->index < stack_a->min + stack_a->total / 6)
	{
		if (stack_a->head->index > max_b)
			make_rotate(stack_a);
		else
		{
			make_push(stack_a, stack_b);
			if (stack_b->head->index > stack_a->min + stack_a->total / 16)
				make_rotate(stack_b);
		}
	}
}

static void	quarter_push(t_stack *stack_b, t_stack *stack_a, int value)
{
	if (stack_b->head->index < value)
		make_push(stack_b, stack_a);
	else
	{
		make_push(stack_b, stack_a);
		make_rotate(stack_a);
	}
}

void	quarter_stack(t_stack *stack_b, t_stack *stack_a)
{
	int	quarter;
	int	max_b;

	set_min_mid_max(stack_b);
	max_b = stack_b->max;
	quarter = stack_b->size * 3 / 4;
	while (!stack_b->head->flag)
		quarter_push(stack_b, stack_a, quarter);
	set_min_mid_max(stack_b);
	while (stack_b->size)
		quarter_push(stack_b, stack_a, stack_b->mid);
	qrtr_stack_back_top(stack_a, stack_b, max_b);
	qrtr_stack_back_btm(stack_a, stack_b, max_b);
	make_rotate(stack_a);
	qrtr_stack_back_top(stack_a, stack_b, max_b);
	qrtr_stack_back_btm(stack_a, stack_b, max_b);
}

void	sort_more_five(t_stack *stack_a, t_stack *stack_b)
{
	int	one_sixteen;

	one_sixteen = stack_a->total / 16;
	if (one_sixteen < 3)
		one_sixteen = 3;
	if (stack_b->size > 128)
		quarter_stack(stack_b, stack_a);
	if (check_sort_stack(stack_a))
	{
		while ((int)stack_a->size > one_sixteen)
			divide_stack(stack_a, stack_b);
		while (stack_a->size > 3)
		{
			if (stack_a->head->index <= stack_a->max - 3)
				make_push(stack_a, stack_b);
			else
				make_rotate(stack_a);
		}
		if (check_sort_stack(stack_a))
			sort_three(stack_a);
	}
	sort_insert(stack_a, stack_b);
}
