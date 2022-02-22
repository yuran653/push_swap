/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 03:17:22 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/22 07:01:16 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_swap(t_stack *stack, char chr)
{
	t_elem	*tmp1;
	t_elem	*tmp2;

	if (stack->size > 1)
	{
		tmp1 = stack->head;
		tmp2 = stack->head->next;
		stack->head->next->next->prev = tmp1;
		tmp1->next = stack->head->next->next;
		tmp2->next = tmp1;
		tmp2->prev = stack->head->prev;
		stack->head->prev->next = tmp2;
		tmp1->prev = tmp2;
		stack->head = tmp2;
	}
	if (chr == 'y')
		ft_printf("s%c\n", stack->name);
}

void	make_swap_both(t_stack *stack_a, t_stack *stack_b)
{
	make_swap(stack_a, '-');
	make_swap(stack_b, '-');
	ft_printf("ss\n");
}
