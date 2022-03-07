/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:49:20 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/07 21:54:32 by jgoldste         ###   ########.fr       */
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
		while (stack_a->head->index != stack_b->head->index + 1)
			make_rotate(stack_a);
		make_push(stack_b, stack_a);
	}
}

void	set_min_max(t_stack *stack)
{
	stack->min = stack->head->index;
	stack->max = stack->head->prev->index;
}

void	sort_min_max(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_b->size + 1;
	while (--i)
	{
		if (stack_b->head->index < stack_a->head->index)
		{
			make_push(stack_b, stack_a);
			set_min_max(stack_a);
		}
		else if (stack_b->head->index > stack_a->head->prev->index)
		{
			make_push(stack_b, stack_a);
			make_rotate(stack_a);
			set_min_max(stack_a);
		}
		else
			sort_insert(stack_a, stack_b);
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = stack_a->size / 2;
	stack_a->mid = stack_a->size / 2;
	while (stack_a->size > stack_a->mid + 1)
		if (stack_a->head->index < stack_a->mid)
			make_push(stack_a, stack_b);
		else
			make_reverse(stack_a);
	// if (!check_sort_stack(stack_a) && stack_a->size == 3)
	// {
	// 	if (stack_a->head->index > stack_a->head->next->index)
	// 	{
	// 		if (stack_a->head->next->index > stack_a->head->prev->index
	// 			|| stack_a->head->prev->index > stack_a->head->index)
	// 			make_swap(stack_a);
	// 	}
	// 	else if (stack_a->head->prev->index > stack_a->head->index)
	// 		make_swap(stack_a);
	// 	if (stack_a->head->index > stack_a->head->next->index)
	// 		make_rotate(stack_a);
	// 	else if (stack_a->head->next->index > stack_a->head->index
	// 		&& stack_a->head->next->index > stack_a->head->prev->index)
	// 		make_reverse(stack_a);
	// }
	// if (stack_b->size)
	// 	sort_min_max(stack_a, stack_b);
	// if (stack_a->size > 3) //!!!!!
	// 	while (stack_a->head->index)
	// 		make_reverse(stack_a);
}
