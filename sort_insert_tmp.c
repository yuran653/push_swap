/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert_tmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:07:29 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/22 19:18:26 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_min_of_max(t_stack *stack_a, t_stack *stack_b)
{
	t_elem	*fix;
	int		i;
	int		min_of_max;

	fix = stack_a->head;
	i = stack_a->size;
	min_of_max = stack_a->total;
	while (i--)
	{
		// ft_printf("\tMIN_OF_MAX = %d\n", min_of_max);
		if (stack_b->head->index < stack_a->head->index)
			if (min_of_max > stack_a->head->index)
				min_of_max = stack_a->head->index;
		if (min_of_max == stack_b->head->index + 1)
		{	
			stack_a->head = fix;
			return (min_of_max);
		}
		stack_a->head = stack_a->head->next;
	}
	stack_a->head = fix;
	return (min_of_max);
}

void	find_min_of_max(t_stack *stack_a, t_stack *stack_b)
{
	t_elem	*fix;
	int		i;
	
	fix = stack_b->head;
	i = stack_b->size;
	while (i--)
	{
		stack_b->head->min_of_max = set_min_of_max(stack_a, stack_b);
		// ft_printf("STACK_B HEAD = %d\nMIN_OF_MAX = %d\n",
			// stack_b->head->index, stack_b->head->min_of_max);
		stack_b->head = stack_b->head->next;
	}
	stack_b->head = fix;
}

void	set_order(t_stack *stack)
{
	t_elem	*fix;
	int		i;

	i = stack->size - 1;
	if (!i)
		stack->head->order = 0;
	else
	{
		fix = stack->head;
		while (i--)
		{
			stack->head->next->order = stack->head->order + 1;
			stack->head = stack->head->next;
		}
		stack->head = fix;
	}
}

void	set_moves(t_stack *stack_a, t_stack *stack_b)
{
	t_elem	*fix_a;
	t_elem	*fix_b;
	int		i;

	fix_b = stack_b->head;
	i = stack_b->size;
	while (i--)
	{
		fix_a = stack_a->head;
		while (stack_a->head->index != stack_b->head->min_of_max)
			stack_a->head = stack_a->head->next;
		// ft_printf("STACK_A HEAD = %d\nMIN_OF_MAX = %d\n",
			// stack_a->head->index, stack_b->head->min_of_max);
		// if (stack_a->head->index == stack_b->head->min_of_max)
		// 	ft_printf("OK\n");
		// else
		// 	ft_printf("---KO---\n");
		stack_a->head = fix_a;
		stack_b->head = stack_b->head->next;
	}
	stack_b->head = fix_b;
}

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
		// if (!check_sort_stack(stack_a))
		// 	ft_printf("\tSTACK_A IS SORTED\n");
		// exit(0);
		set_order(stack_a);
		set_order(stack_b);
		find_min_of_max(stack_a, stack_b);
		// ft_printf("STACK_A FIRST = %d\nSTACK_A NEXT = %d\nSTACK_A LAST= %d\n",
		// 	stack_a->head->order, stack_a->head->next->order, stack_a->head->prev->order);
		// ft_printf("STACK_B FIRST = %d\nSTACK_B NEXT = %d\nSTACK_B = %d\n",
		// 	stack_b->head->order, stack_b->head->next->order, stack_b->head->prev->order);
		// ft_printf("STACK_B HEAD = %d\nMIN_OF_MAX = %d\n",
		// 	stack_b->head->index, stack_b->head->min_of_max);
		// ft_printf("MOVES FOR NEXT_A = %d\n", stack_a->head->next->order);
		// ft_printf("MOVES FOR PREV_A = %d\n", stack_a->size - stack_a->head->prev->order);
		// ft_printf("MOVES FOR NEXT_B = %d\n", stack_b->head->next->order);
		// ft_printf("MOVES FOR PREV_B = %d\n", stack_b->size - stack_b->head->prev->order);
		set_moves(stack_a, stack_b);
		if (!check_sort_stack(stack_a))
			ft_printf("\tSTACK_A IS SORTED\n\tSTACK_B SIZE = %d\n", stack_b->size);
		exit(0);
	}
}