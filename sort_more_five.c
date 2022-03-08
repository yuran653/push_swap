/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:11:13 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/09 01:42:54 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_min_mid_max(t_stack *stack)
{
	t_elem	*fix;
	int		stop;

	fix = stack->head;
	stop = stack->size - 1;
	stack->min = stack->head->index;
	stack->max = stack->head->index;
	while (stop--)
	{
		if (stack->head->next->index > stack->head->index 
			&& stack->head->next->index > stack->max)
			stack->max = stack->head->next->index;
		if (stack->head->next->index < stack->head->index 
			&& stack->head->next->index < stack->min)
			stack->min = stack->head->next->index;
			stack->head = stack->head->next;
	}
	stack->mid = (stack->max + stack->min) / 2 + (stack->max + stack->min) % 2;
	stack->head = fix;
}

void	sort_more_five(t_stack *stack_a, t_stack *stack_b)
{
	if (check_sort_stack(stack_a))
	{
		while (stack_a->size > 3)
			divide_stack(stack_a, stack_b);
		if (check_sort_stack(stack_a))
			sort_three(stack_a);
		make_push(stack_b, stack_a);
	}
}