/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 03:20:56 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/22 05:11:24 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_reverse(t_stack *stack, char chr)
{
	if (stack->size > 1)
		stack->head = stack->head->prev;
	if (chr == 'a')
		write(1, "rra\n", 4);
	if (chr == 'b')
		write(1, "rrb\n", 4);
}

void	make_reverse_both(t_stack *stack_a, t_stack *stack_b)
{
	make_rotate(stack_a, 'a');
	make_rotate(stack_b, 'b');
	write(1, "rrr\n", 4);
}