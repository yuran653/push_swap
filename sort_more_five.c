/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:11:13 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/17 09:45:21 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quarter_stack_back(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->head->index <
		stack_a->total / 8 + stack_a->total % 8 + stack_a->min)
	{
		make_push(stack_a, stack_b);
		if (stack_b->head->index > stack_a->total / 16 + stack_a->min)
			make_rotate(stack_b);
	}
	make_reverse(stack_a);
	set_min_mid_max(stack_a);
	while (stack_a->head->index <
		stack_a->total / 8 + stack_a->total % 8 + stack_a->min)
	{
		make_push(stack_a, stack_b);
		make_reverse(stack_a);
		if (stack_b->head->index > stack_a->total / 16 + stack_a->min)
			make_rotate(stack_b);
	}
	set_min_mid_max(stack_a);
}

void	quarter_push(t_stack *stack_b, t_stack *stack_a, int value)
{
	if (stack_b->head->index < value)
		make_push(stack_b, stack_a);
	else
	{
		make_push(stack_b, stack_a);
		make_rotate(stack_a);
	}
}

void	quarter_stack_b(t_stack *stack_b, t_stack *stack_a)
{
	unsigned int	half;
	int				quarter;

	half = stack_b->size / 2;
	set_min_mid_max(stack_b);
	quarter = stack_b->size * 3 / 4;
	while ((int)stack_b->size != stack_b->mid)
		quarter_push(stack_b, stack_a, quarter);
	set_min_mid_max(stack_b);
	while (stack_b->size)
		quarter_push(stack_b, stack_a, stack_b->mid);
	set_min_mid_max(stack_a);
	quarter_stack_back(stack_a, stack_b);
	make_rotate(stack_a);
	quarter_stack_back(stack_a, stack_b);
}

void	quarter_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	// ft_printf("MIN = %d\nMAX = %d\nSIZE = %d\n",
	// 	stack_a->min, stack_a->max, stack_a->size);
	// int amount = stack_a->size / 4;
	// int value = amount + stack_a->min;
	// int	quarter = stack_a->size - stack_a->size / 4;
	// ft_printf("TOTAL = %d\n", amount + quarter);
	// ft_printf("AMOUNT = %d\nVALUE = %d\nQUARTER = %d\n", amount, value, quarter);
	// ft_printf("TOP = %d\nBTM = %d\n",
	// 	check_min_top(stack_a, value),
	// 	check_min_btm(stack_a, value));
	// (void) stack_b;
	// exit(0);
	/*int amount = stack_a->size / 4;*/
	int value_a = stack_a->min + stack_a->size / 4;
	int	value_b = stack_a->min + stack_a->size / 4 / 2;
	int	size_a = stack_a->size - stack_a->size / 4;
	// int	rotate;

	// if (check_min_btm(stack_a, value_a) <= check_min_top(stack_a, value_a))
	// 	rotate = 1;
	// else
	// 	rotate = 0;
	while ((int)stack_a->size > size_a)
	{
		if (stack_a->head->index < value_a)
		{
			make_push(stack_a, stack_b);
			if (stack_b->head->index < value_b)
				make_rotate(stack_b);
		}

		// if (rotate)
		// 	make_rotate(stack_a);
		// else
		// 	make_reverse(stack_a);

		if (check_min_btm(stack_a, value_a) <= check_min_top(stack_a, value_a))
			make_rotate(stack_a);
		else
			make_reverse(stack_a);
	}
}

void	sort_more_five(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size > 100)
	{
		quarter_stack_b(stack_b, stack_a);
		quarter_stack_a(stack_a, stack_b);
	}
	if (check_sort_stack(stack_a))
	{
		while (stack_a->size > 3)
			divide_stack(stack_a, stack_b);
		if (check_sort_stack(stack_a))
			sort_three(stack_a);
	}
	// exit(0);
	sort_insert(stack_a, stack_b);
}

// void	divide_eighth(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_elem	*fix;
// 	int		min;
// 	int		max;
// 	int		stop;

// 	fix = stack_a->head;
// 	max = stack_a->head->index;
// 	min = stack_a->head->index;
// 	stop = stack_a->size / 8 + stack_a->size % 8 + stack_a->min;
// 	while (stack_a->head->index <= stop)
// 	{
// 		if(stack_a->head->index > max)
// 			max = stack_a->head->index;
// 		if(stack_a->head->index < min)
// 			min = stack_b->head->index;
// 		stack_a->head = stack_a->head->next;
// 	}
// 	stack_a->head = fix;
// 	while (stack_a->head->index <= max)
// 	{
// 		make_push(stack_a, stack_b);
// 		if (stack_b->head->index > (min + max) / 2)
// 			make_rotate(stack_b);
// 	}
// 	set_min_mid_max(stack_a);
// 	make_reverse(stack_a);
// 	fix = stack_a->head;
// 	max = stack_a->head->index;
// 	min = stack_a->head->index;
// 	stop = stack_a->size / 8 + stack_a->size % 8 + stack_a->min;
// 	while (stack_a->head->index <= stop)
// 	{
// 		if(stack_a->head->index > max)
// 			max = stack_a->head->index;
// 		if (stack_a->head->index < min)
// 			min = stack_b->head->index;
// 		stack_a->head = stack_a->head->prev;
// 	}
// 	stack_a->head = fix;
// 	// set_min_mid_max(stack_a);
// 	// ft_printf("---BTM---\nMIN = %d\nMAX = %d\n", min, max);
// 	// ft_printf("--STACK--\nMIN = %d\nMAX = %d\n", stack_a->min, stack_a->max);
// 	// exit (0);
// 	// while (stack_a->head->index <= max)
// 	// {
// 	// 	make_push(stack_a, stack_b);
// 	// 	if (stack_b->head->index > (min + max) / 2)
// 	// 		make_rotate(stack_b);
// 	// 	make_reverse(stack_a);
// 	// }
// 	// // ft_printf("MIN = %d\nMAX = %d\nSIZE = %d\nSTOP = %d\n",
// 	// // 	stack_a->min, stack_a->max, stack_a->size, stop);
// 	// // (void) stack_b;
// 	// exit(0);
// }

// void	divide_quarter(t_stack *stack_a, t_stack *stack_b)
// {
// 	t_elem	*fix;
// 	int		max;
// 	int		min;
// 	int		stop;

// 	fix = stack_b->head;
// 	max = stack_b->head->index;
// 	min = stack_b->head->index;
// 	stop = stack_b->total / 2 + stack_b->total % 2;
// 	while (stack_b->head->index >= stop)
// 	{
// 		if (stack_b->head->index > max)
// 			max = stack_b->head->index;
// 		if (stack_b->head->index < min)
// 			min = stack_b->head->index;
// 		stack_b->head = stack_b->head->next;
// 	}
// 	stack_b->head = fix;
// 	while (stack_b->head->index >= min)
// 	{
// 		make_push(stack_b, stack_a);
// 		if (stack_a->head->index > (min + max) / 2)
// 			make_rotate(stack_a);
// 	}
// 	make_reverse(stack_b);
// 	fix = stack_b->head;
// 	max = stack_b->head->index;
// 	min = stack_b->head->index;
// 	stop = stack_b->total / 2 + stack_b->total % 2;
// 	while (stack_b->head->index >= stop)
// 	{
// 		if (stack_b->head->index > max)
// 			max = stack_b->head->index;
// 		if (stack_b->head->index < min)
// 			min = stack_b->head->index;
// 		stack_b->head = stack_b->head->prev;
// 	}
// 	stack_b->head = fix;
// 	while (stack_b->head->index >= min)
// 	{
// 		make_push(stack_b, stack_a);
// 		if (stack_a->head->index > (min + max) / 2)
// 			make_rotate(stack_a);
// 		make_reverse(stack_b);
// 	}
// 	set_min_mid_max(stack_a);
// }