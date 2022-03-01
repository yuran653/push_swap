/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:49:20 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/01 22:48:53 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_insert(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->head->number < stack_a->head->number
		&& stack_b->head->number > stack_a->head->next->number)
		{
			make_rotate(stack_a);
			make_push(stack_b, stack_a);
		}
	else if (stack_b->head->number < stack_a->head->prev->number
		&& stack_b->head->number > stack_a->head->prev->prev->number)
		{
			make_reverse(stack_b);
			make_push(stack_b, stack_a);
		}
	else
	{
		make_reverse(stack_a);
		make_reverse(stack_a);
		make_push(stack_b, stack_a);
	}
}

void	sort_next(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_b->size;
	while (i--)
	{
		if (stack_b->head->number < stack_a->head->number)
		{
			make_push(stack_b, stack_a);
			stack_a->min = stack_a->head->number;
		}
		else if (stack_b->head->number > stack_a->head->number)
		{
			make_push(stack_b, stack_a);
			make_reverse(stack_a);
			stack_a->max = stack_a->head->prev->number;
		}
		else
		{
			stack_a->min = stack_a->head->number;
			stack_a->max = stack_a->head->prev->number;
			sort_insert(stack_a, stack_b);
		}
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
		make_push(stack_a, stack_b);
	if (!check_sort(stack_a))
	{
		if (stack_a->head->number > stack_a->head->next->number)
		{
			if (stack_a->head->next->number > stack_a->head->prev->number
				|| stack_a->head->prev->number > stack_a->head->number)
				make_swap(stack_a);
		}
		else if (stack_a->head->prev->number > stack_a->head->number)
			make_swap(stack_a);
		if (stack_a->head->number > stack_a->head->next->number)
			make_rotate(stack_a);
		else if (stack_a->head->next->number > stack_a->head->number
			&& stack_a->head->next->number > stack_a->head->prev->number)
			make_reverse(stack_a);
	}
	// if (stack_b->size)
	// 	sort_next(stack_a, stack_b);
	// if (stack_a->size > 3)
	// 	while (stack_a->head->number != stack_a->min)
	// 		make_reverse(stack_a);
}

