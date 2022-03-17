/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:21:28 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/17 08:30:53 by jgoldste         ###   ########.fr       */
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

int	check_max_top(t_stack *stack)
{
	t_elem	*fix;
	int		top;
	int		i;

	fix = stack->head;
	top = 0;
	i = stack->size / 2 + stack->size % 2;
	while(i--)
	{
		if(stack->head->next->index > stack->mid)
			top++;
		stack->head = stack->head->next;
	}
	stack->head = fix;
	return (top);
}

int	check_max_btm(t_stack *stack)
{
	t_elem	*fix;
	int		btm;
	int		i;

	fix = stack->head;
	btm = 0;
	i = stack->size / 2;
	while(i--)
	{
		if (stack->head->prev->index > stack->mid)
			btm++;
		stack->head =stack->head->prev;
	}
	stack->head = fix;
	return (btm);
}

int	check_min_top(t_stack *stack, int value)
{
	t_elem	*fix;
	int		top;
	int		i;

	fix = stack->head;
	top = 0;
	i = stack->size / 2 + stack->size % 2;
	while(i--)
	{
		if(stack->head->next->index < value)
			top++;
		stack->head = stack->head->next;
	}
	stack->head = fix;
	return (top);
}

int	check_min_btm(t_stack *stack, int value)
{
	t_elem	*fix;
	int		btm;
	int		i;

	fix = stack->head;
	btm = 0;
	i = stack->size / 2;
	while(i--)
	{
		if (stack->head->prev->index < value)
			btm++;
		stack->head =stack->head->prev;
	}
	stack->head = fix;
	return (btm);
}
