/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:25:36 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/11 21:23:52 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort_stack(t_stack *stack)
{
	int		i;
	t_elem	*tmp;

	i = stack->size - 1;
	tmp = stack->head;
	while (i--)
	{
		if (stack->head->index > stack->head->next->index)
		{
			stack->head = tmp;
			return (1);
		}
		else
			stack->head = stack->head->next;
	}
	stack->head = tmp;
	return (0);
}

void	set_min_mid_max(t_stack *stack)
{
	t_elem	*fix;
	int		stop;

	fix = stack->head;
	stop = stack->size - 1;
	stack->min = stack->head->index;
	stack->max = stack->head->index;
	while (stop--)
	{
		if (stack->head->next->index > stack->head->index 
			&& stack->head->next->index > stack->max)
			stack->max = stack->head->next->index;
		if (stack->head->next->index < stack->head->index 
			&& stack->head->next->index < stack->min)
			stack->min = stack->head->next->index;
			stack->head = stack->head->next;
	}
	stack->mid = (stack->max + stack->min) / 2 + (stack->max + stack->min) % 2;
	if (stack->size == 4)
		stack->mid--;
	stack->head = fix;
}

void	divide_stack_max(t_stack *stack_src, t_stack *stack_dst)
{
	unsigned int	half;

	half = stack_src->size / 2;
	set_min_mid_max(stack_src);
	while (stack_src->size > half)
	{
		if (stack_src->head->index >= stack_src->mid)
			make_push(stack_src, stack_dst);
		else
		{
			if (check_max_btm(stack_src) <= check_max_top(stack_src))
				make_rotate(stack_src);
			else
				make_reverse(stack_src);
		}
	}
	set_min_mid_max(stack_src);
	set_min_mid_max(stack_dst);
}

void	sort_pre_min(t_stack *stack_src, t_stack *stack_dst)
{
	int	mid_dst;

	mid_dst = (stack_src->mid + stack_src->min) / 2;
	if (stack_src->head->index < stack_src->mid)
	{
		if (stack_src->head->index > mid_dst)
			make_push(stack_src, stack_dst);
		else
		{
			make_push(stack_src, stack_dst);
			make_rotate(stack_dst);
		}
	}
	else
	{
		if (check_min_btm(stack_src) <= check_min_top(stack_src))
			make_rotate(stack_src);
		else
			make_reverse(stack_src);
	}
	// ft_printf("\tMIN = %d\n\tMID = %d\n\tQUARTER = %d\n\tMAX = %d\n",
	// 	stack_src->min, stack_src->mid, mid_dst, stack_src->max);
}

void	divide_stack_min(t_stack *stack_src, t_stack *stack_dst)
{
	unsigned int	half;
	
	half = stack_src->size / 2 + stack_src->size % 2;
	set_min_mid_max(stack_src);
	if (half < 3)
		half = 3;
	while (stack_src->size > half)
		sort_pre_min(stack_src, stack_dst);
	set_min_mid_max(stack_src);
	set_min_mid_max(stack_dst);
}
