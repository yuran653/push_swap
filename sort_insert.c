/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 23:01:55 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/23 01:08:29 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_insert(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size)
	{
		while (stack_b->head->index < stack_a->head->index
			|| (stack_b->head->index < stack_a->head->next->index
			&& stack_b->head->index > stack_a->head->index))
			{
				make_push(stack_b, stack_a);
				if (stack_a->head->index > stack_a->head->next->index)
				{
					if (stack_b->head->index < stack_b->head->next->index)
						make_swap_both(stack_a, stack_b);
					else
						make_swap(stack_a);
				}
			}
		if (stack_b->head->index < stack_a->head->index
			&& stack_b->head->index < stack_a->head->prev->index)
			{
			while (stack_b->head->index > stack_a->head->index)
				make_reverse(stack_a);
			make_push(stack_b, stack_a);
			}
		else if (stack_b->head->index > stack_a->head->index)
		{
			while (stack_b->head->index > stack_a->head->index)
				make_rotate(stack_a);
			make_push(stack_b, stack_a);
		}
		else
		{
			if (!check_sort_stack(stack_a))
				ft_printf("\tSTACK_A IS SORTED\n");
			ft_printf("\tSTACK_A SIZE = %d\n", stack_a->size);
			exit(0);
		}
	}
	if (!check_sort_stack(stack_a))
		ft_printf("\tSTACK_A IS SORTED\n");
	ft_printf("\tSTACK_A SIZE = %d\n", stack_a->size);
	exit(0);
}
