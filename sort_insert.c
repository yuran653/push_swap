/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:34:22 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/24 20:36:17 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_insert(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->head->index < stack_a->head->index
			|| (stack_b->head->index < stack_a->head->next->index
			&& stack_b->head->index > stack_a->head->index))
			{
				make_push(stack_b, stack_a);
				if (stack_a->head->index > stack_a->head->next->index)
					make_swap(stack_a);
			}
	exit(0);
}