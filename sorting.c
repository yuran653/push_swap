/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:49:20 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/01 00:00:51 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3)
		make_push(stack_a, stack_b);
	if (stack_a->head->number > stack_a->head->next->number
		&& stack_a->head->number > stack_a->head->prev->number)
	{
		if (stack_a->head->next->number < stack_a->head->prev->number)
			make_rotate(stack_a);
		else
			make_swap(stack_a);
	}
	if (stack_a->head->next->number > stack_a->head->prev->number)
	{
		
	}	

	// if (stack_a->head->number < stack_a->head->next->number)
	// 	make_reverse(stack_a);
	// if (stack_a->head->number > stack_a->head->next->number
	// 	&& stack_a->head->number < stack_a->head->prev->number)
	// 	make_swap(stack_a);
	// if (stack_a->head->number > stack_a->head->next->number)
	// {
	// 	if (stack_a->head->next->number > stack_a->head->prev->number)
	// 		make_reverse(stack_a);
	// 	else
	// 		make_rotate(stack_a);
	// }
		
	// if (stack_a->head->number < stack_a->head->next->number)
	// {
	// 	if (stack_a->head->number < stack_a->head->prev->number)
	// 		make_rotate(stack_a);
	// 	else
	// 		make_reverse(stack_a);
	// }
	// if (stack_a->head->number > stack_a->head->next->number)
	// {
	// 	make_swap(stack_a);
	// 	if (stack_a->head->number > stack_a->head->prev->number)
	// 		make_reverse(stack_a);
	// }
}
