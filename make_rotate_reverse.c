/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rotate_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 03:20:50 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/25 06:55:55 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_rotate(t_stack *stack)
{
	if (stack->size > 1)
	{
		stack->head = stack->head->next;
		if (stack->name == 'a' || stack->name == 'b')
			ft_printf("r%c\n", stack->name);
	}
}

void	make_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 1 || stack_b->size > 1)
	{
		stack_a->name = 'n';
		stack_b->name = 'n';
		make_rotate(stack_a);
		make_rotate(stack_b);
		ft_printf("rr\n");
		stack_a->name = 'a';
		stack_b->name = 'b';
	}
}

void	make_reverse(t_stack *stack)
{
	if (stack->size > 1)
	{
		stack->head = stack->head->prev;
		if (stack->name == 'a' || stack->name == 'b')
			ft_printf("rr%c\n", stack->name);
	}
}

void	make_reverse_both(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 1 || stack_b->size > 1)
	{
		stack_a->name = 'n';
		stack_b->name = 'n';
		make_rotate(stack_a);
		make_rotate(stack_b);
		ft_printf("rrr\n");
		stack_a->name = 'a';
		stack_b->name = 'b';
	}
}
