/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:49:20 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/07 18:16:02 by jgoldste         ###   ########.fr       */
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
		if (stack->head->next->number > stack->head->number)
		{
			if (!i)
			{	
				stack->head = tmp;
				return (1);
			}
			stack->head = stack->head->next;
		}
	}
	stack->head = tmp;
	return (0);
}

void	sort_insert(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->head->index < stack_a->head->index
		&& stack_b->head->index > stack_a->head->next->index)
		{
			make_rotate(stack_a);
			make_push(stack_b, stack_a);
		}
	else if (stack_b->head->index < stack_a->head->prev->index
		&& stack_b->head->index > stack_a->head->prev->prev->index)
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
		if (stack_b->head->index < stack_a->head->index)
		{
			make_push(stack_b, stack_a);
			stack_a->min = stack_a->head->index;
		}
		else if (stack_b->head->index > stack_a->head->index)
		{
			make_push(stack_b, stack_a);
			make_reverse(stack_a);
			stack_a->max = stack_a->head->prev->index;
		}
		else
		{
			stack_a->min = stack_a->head->index;
			stack_a->max = stack_a->head->prev->index;
			sort_insert(stack_a, stack_b);
		}
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
		make_push(stack_a, stack_b);
	if (!check_sort_stack(stack_a))
	{
		if (stack_a->head->index > stack_a->head->next->index)
		{
			if (stack_a->head->next->index > stack_a->head->prev->index
				|| stack_a->head->prev->index > stack_a->head->index)
				make_swap(stack_a);
		}
		else if (stack_a->head->prev->index > stack_a->head->index)
			make_swap(stack_a);
		if (stack_a->head->index > stack_a->head->next->index)
			make_rotate(stack_a);
		else if (stack_a->head->next->index > stack_a->head->index
			&& stack_a->head->next->index > stack_a->head->prev->index)
			make_reverse(stack_a);
	}
	if (stack_b->size)
		sort_next(stack_a, stack_b);
	if (stack_a->size > 3)
		while (stack_a->head->index != stack_a->min)
			make_reverse(stack_a);
}
