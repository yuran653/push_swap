/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rotate_reverse_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 03:20:50 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/29 16:18:15 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_rotate(t_stack *stack)
{
	if (stack->size > 1)
		stack->head = stack->head->next;
}

void	make_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 1 || stack_b->size > 1)
	{
		make_rotate(stack_a);
		make_rotate(stack_b);
	}
}

void	make_reverse(t_stack *stack)
{
	if (stack->size > 1)
		stack->head = stack->head->prev;
}

void	make_reverse_both(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 1 || stack_b->size > 1)
	{
		make_rotate(stack_a);
		make_rotate(stack_b);
	}
}
