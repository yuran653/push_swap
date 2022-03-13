/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_upto_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:49:20 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/12 20:50:38 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_upto_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size == 1)
	{
		make_push(stack_b, stack_a);
		if (stack_a->head->index > stack_a->head->next->index)
			make_swap(stack_a);
	}
	if (stack_b->size == 2)
	{
		if (stack_b->head->index < stack_b->head->next->index)
			make_swap(stack_b);
		while (stack_b->size)
			make_push(stack_b, stack_a);
	}
}

void	sort_three(t_stack *stack)
{
	if (stack->head->index > stack->head->next->index)
	{
		if (stack->head->next->index > stack->head->prev->index
			|| stack->head->prev->index > stack->head->index)
			make_swap(stack);
	}
	else if (stack->head->prev->index > stack->head->index)
		make_swap(stack);
	if (stack->head->index > stack->head->next->index
		&& stack->head->index > stack->head->prev->index)
			make_rotate(stack);
	if (stack->head->next->index > stack->head->prev->index)
		make_reverse(stack);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	set_min_mid_max(stack_a);
	stack_a->total = stack_a->max;
	stack_b->total = stack_a->max;
	if (stack_a->size > 3)
		divide_stack(stack_a, stack_b);
	if (check_sort_stack(stack_a) && stack_a->size == 3)
		sort_three(stack_a);
	if (stack_b->size)
		sort_upto_five(stack_a, stack_b);
	if (stack_b->size)
		sort_more_five(stack_a, stack_b);
}
