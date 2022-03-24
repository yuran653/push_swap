/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:25:36 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/24 21:54:05 by jgoldste         ###   ########.fr       */
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

void	divide_stack(t_stack *stack_src, t_stack *stack_dst)
{
	unsigned int	half;
	int	mid_dst;

	mid_dst = (stack_src->mid + stack_src->min) / 2;
	half = stack_src->size / 2 + stack_src->size % 2;
	set_min_mid_max(stack_src);
	if (half < 3)
		half = 3;
	while (stack_src->size > half)
	{
		if (stack_src->head->index < stack_src->mid)
			make_push(stack_src, stack_dst);
		else
			make_rotate(stack_src);
	}
	set_min_mid_max(stack_src);
	set_min_mid_max(stack_dst);
}


// void	divide_stack(t_stack *stack_src, t_stack *stack_dst)
// {
// 	unsigned int	half;
// 	int				mid_dst;

// 	set_min_mid_max(stack_src);
// 	mid_dst = (stack_src->mid + stack_src->min) / 2;
// 	half = stack_src->size / 2 + stack_src->size % 2;
// 	if (half < 3)
// 		half = 3;
// 	while (stack_src->size > half)
// 	{
// 		if (stack_src->head->index < stack_src->mid)
// 		{
// 			if (stack_src->head->index > mid_dst)
// 				make_push(stack_src, stack_dst);
// 			else
// 			{
// 				make_push(stack_src, stack_dst);
// 				make_rotate(stack_dst);
// 			}
// 		}
// 		else
// 			make_rotate(stack_src);
// 	}
// 	set_min_mid_max(stack_src);
// }
