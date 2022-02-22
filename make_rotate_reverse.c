/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rotate_reverse.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 03:20:50 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/22 07:03:49 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_rotate(t_stack *stack, char chr)
{
	if (stack->size > 1)
		stack->head = stack->head->next;
	if (chr == 'y')
		ft_printf("r%c\n", stack->name);
}

void	make_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	make_rotate(stack_a, '-');
	make_rotate(stack_b, '-');
	ft_printf("rr\n");
}

void	make_reverse(t_stack *stack, char chr)
{
	if (stack->size > 1)
		stack->head = stack->head->prev;
	if (chr == 'y')
		ft_printf("rr%c\n", stack->name);
}

void	make_reverse_both(t_stack *stack_a, t_stack *stack_b)
{
	make_rotate(stack_a, 'a');
	make_rotate(stack_b, 'b');
	ft_printf("rrr\n");
}