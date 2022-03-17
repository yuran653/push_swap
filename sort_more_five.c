/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:11:13 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/18 00:01:12 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quarter_stack_back(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->head->index
		< stack_a->total / 8 + stack_a->total % 8 + stack_a->min)
	{
		make_push(stack_a, stack_b);
		if (stack_b->head->index > stack_a->total / 16 + stack_a->min)
			make_rotate(stack_b);
	}
	make_reverse(stack_a);
	set_min_mid_max(stack_a);
	while (stack_a->head->index
		< stack_a->total / 8 + stack_a->total % 8 + stack_a->min)
	{
		make_push(stack_a, stack_b);
		make_reverse(stack_a);
		if (stack_b->head->index > stack_a->total / 16 + stack_a->min)
			make_rotate(stack_b);
	}
	set_min_mid_max(stack_a);
}

void	quarter_push(t_stack *stack_b, t_stack *stack_a, int value)
{
	if (stack_b->head->index < value)
		make_push(stack_b, stack_a);
	else
	{
		make_push(stack_b, stack_a);
		make_rotate(stack_a);
	}
}

void	quarter_stack_b(t_stack *stack_b, t_stack *stack_a)
{
	unsigned int	half;
	int				quarter;

	half = stack_b->size / 2;
	set_min_mid_max(stack_b);
	quarter = stack_b->size * 3 / 4;
	while ((int)stack_b->size != stack_b->mid)
		quarter_push(stack_b, stack_a, quarter);
	set_min_mid_max(stack_b);
	while (stack_b->size)
		quarter_push(stack_b, stack_a, stack_b->mid);
	set_min_mid_max(stack_a);
	quarter_stack_back(stack_a, stack_b);
	make_rotate(stack_a);
	quarter_stack_back(stack_a, stack_b);
}

void	quarter_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	value_a;
	int	value_b;
	int	size_a;

	value_a = stack_a->min + stack_a->size / 4;
	value_b = stack_a->min + stack_a->size / 4 / 2;
	size_a = stack_a->size - stack_a->size / 4;
	while ((int)stack_a->size > size_a)
	{
		if (stack_a->head->index < value_a)
		{
			make_push(stack_a, stack_b);
			if (stack_b->head->index < value_b)
				make_rotate(stack_b);
		}
		if (check_min_btm(stack_a, value_a) <= check_min_top(stack_a, value_a))
			make_rotate(stack_a);
		else
			make_reverse(stack_a);
	}
}

void	sort_more_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size > 100)
	{
		quarter_stack_b(stack_b, stack_a);
		quarter_stack_a(stack_a, stack_b);
	}
	if (check_sort_stack(stack_a))
	{
		while (stack_a->size > 3)
			divide_stack(stack_a, stack_b);
		if (check_sort_stack(stack_a))
			sort_three(stack_a);
	}
	sort_insert(stack_a, stack_b);
}
