/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:25:36 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/09 18:35:17 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	stack->head = fix;
}

int	check_top(t_stack *stack)
{
	t_elem	*fix;
	int		top;
	int		i;

	fix = stack->head;
	top = 0;
	i = stack->size / 2 + stack->size % 2;
	while(i--)
	{
		if(stack->head->next->index < stack->mid)
			top++;
		stack->head = stack->head->next;
	}
	stack->head = fix;
	return (top);
}

int	check_btm(t_stack *stack)
{
	t_elem	*fix;
	int		btm;
	int		i;

	fix = stack->head;
	btm = 0;
	i = stack->size / 2;
	while(i--)
	{
		if (stack->head->prev->index < stack->mid)
			btm++;
		stack->head =stack->head->prev;
	}
	stack->head = fix;
	return (btm);
}
