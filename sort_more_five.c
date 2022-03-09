/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:11:13 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/10 02:08:47 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_top(t_stack *stack, int value)
{
	t_elem	*fix;
	int		i;

	fix = stack->head;
	i = stack->size / 2 + stack->size % 2;
	while(i--)
	{
		if(stack->head->next->index == value)
		{
			stack->head = fix;
			return (1);
		}
		stack->head = stack->head->next;
	}
	stack->head = fix;
	return (0);
}

int	find_btm(t_stack *stack, int value)
{
	t_elem	*fix;
	int		i;

	fix = stack->head;
	i = stack->size / 2;
	while(i--)
	{
		if (stack->head->prev->index == value)
		{
			stack->head = fix;
			return (1);
		}
		stack->head =stack->head->prev;
	}
	stack->head = fix;
	return (0);
}

void	sort_more_five(t_stack *stack_a, t_stack *stack_b)
{
	if (check_sort_stack(stack_a))
	{
		while (stack_a->size > 3)
			divide_stack(stack_a, stack_b);
		if (check_sort_stack(stack_a))
			sort_three(stack_a);
	}
	set_min_mid_max(stack_b);
	while (stack_b->size)
	{
		if (stack_b->size < 3)
			sort_upto_five(stack_a, stack_b);
		else if (stack_b->head->index == stack_a->head->index - 1)
			make_push(stack_b, stack_a);
		else if (find_top(stack_b, stack_a->head->index - 1))
		{
			while (stack_b->head->index != stack_a->head->index - 1)
				make_rotate(stack_b);
			make_push(stack_b, stack_a);
		}
		else if (find_btm(stack_b, stack_a->head->index - 1))
		{
			while (stack_b->head->index != stack_a->head->index - 1)
				make_reverse(stack_b);
			make_push(stack_b, stack_a);
		}
	}
}
