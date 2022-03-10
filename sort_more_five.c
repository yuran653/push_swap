/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:11:13 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/10 23:08:31 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_more_five(t_stack *stack_a, t_stack *stack_b)
{
	// divide_stack_max(stack_b, stack_a);
	if (check_sort_stack(stack_a))
	{
		while (stack_a->size > 3)
			divide_stack_min(stack_a, stack_b);
		if (check_sort_stack(stack_a))
			sort_three(stack_a);
	}
	if (stack_b->size)
		set_min_mid_max(stack_b);
	sort_insert(stack_a, stack_b);
}
