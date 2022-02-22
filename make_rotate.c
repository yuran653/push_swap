/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 03:20:50 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/22 05:08:03 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_rotate(t_stack *stack, char chr)
{
	if (stack->size > 1)
		stack->head = stack->head->next;
	if (chr == 'a')
		write(1, "ra\n", 3);
	if (chr == 'b')
		write(1, "rb\n", 3);
}

void	make_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	make_rotate(stack_a, '-');
	make_rotate(stack_b, '-');
	write(1, "rr\n", 3);
}
