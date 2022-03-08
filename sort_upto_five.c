/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_upto_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:49:20 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/09 01:05:29 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort_stack(t_stack *stack)
{
	int		i;
	t_elem	*tmp;

	i = stack->size - 1;
	tmp = stack->head;
	while (i--)
	{
		if (stack->head->index > stack->head->next->index)
		{
			stack->head = tmp;
			return (1);
		}
		else
			stack->head = stack->head->next;
	}
	stack->head = tmp;
	return (0);
}

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

void	divide_stack(t_stack *stack_src, t_stack *stack_dst)
{
	int	half;

	set_min_mid_max(stack_src);
	half = stack_src->size / 2 + stack_src->size % 2;
	if (half < 3)
		half = 3;
	if (stack_src->size > 3)
	{
		while (stack_src->size > half)
		{
			if (stack_src->head->index < stack_src->mid)
				make_push(stack_src, stack_dst);
			else if (stack_src->head->next->index < stack_src->mid
				|| stack_src->head->next->next->index < stack_src->mid)
				make_rotate(stack_src);
			else
				make_reverse(stack_src);
		}
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	divide_stack(stack_a, stack_b);
	if (check_sort_stack(stack_a) && stack_a->size == 3)
		sort_three(stack_a);
	sort_upto_five(stack_a, stack_b);
	sort_more_five(stack_a, stack_b);
}
