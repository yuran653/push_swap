/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:11:13 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/12 05:35:10 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_push_two(t_stack *stack_src, t_stack *stack_dst)
{

}

void	sort_half(t_stack *stack_src, t_stack *stack_dst)
{
	int	i;

	i = 1;
	while (++i < stack_src->mid)
	{
		make_push_two(stack_src, stack_dst);
	}
	exit(0);
}

void	quarter_push(t_stack *stack_src, t_stack *stack_dst, int value)
{
	if (stack_src->head->index < value)
		make_push(stack_src, stack_dst);
	else
	{
		make_push(stack_src, stack_dst);
		make_rotate(stack_dst);
	}
}

void	quarter_stack(t_stack *stack_src, t_stack *stack_dst)
{
	unsigned int	half;
	int				quarter;
	// int				amount;

	half = stack_src->size / 2;
	set_min_mid_max(stack_src);
	quarter = (stack_src->mid + stack_src->max) / 2;
	// amount = stack_src->max;
	while ((int)stack_src->size != stack_src->mid)
		quarter_push(stack_src, stack_dst, quarter);
	set_min_mid_max(stack_src);
	while (stack_src->size)
		quarter_push(stack_src, stack_dst, stack_src->mid);
	set_min_mid_max(stack_dst);
	sort_half(stack_dst, stack_src);
	// ft_printf("MID = %d\n", stack_dst->mid);
	// exit(0);
}

void	sort_more_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size > 100)
		quarter_stack(stack_b, stack_a);
	if (check_sort_stack(stack_a))
	{
		while (stack_a->size > 3)
			divide_stack(stack_a, stack_b);
		if (check_sort_stack(stack_a))
			sort_three(stack_a);
	}
	sort_insert(stack_a, stack_b);
}
