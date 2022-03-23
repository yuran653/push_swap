/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:07:29 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/23 17:39:56 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <fcntl.h>

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

static void	count_moves_top(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->head->direction = 1;
	if (stack_a->head->order > (int)stack_a->size / 2)
	{
		stack_b->head->moves = stack_b->head->order
			+ (stack_a->size - stack_a->head->order);
		// stack_b->head->direction = 1;
		stack_a->head->direction = -1;
	}
	else
	{
		if (stack_b->head->order > stack_a->head->order)
			stack_b->head->moves = stack_b->head->order;
		else
			stack_b->head->moves = stack_a->head->order;
		// stack_b->head->moves = stack_b->head->order + stack_a->head->order;
		// stack_b->head->direction = 1;
		stack_a->head->direction = 1;
	}
}

static void	count_moves_btm(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->head->direction = -1;
	if (stack_a->head->order > (int)stack_a->size / 2)
	{
		if (stack_b->size - stack_b->head->order
			> stack_a->size - stack_a->head->order)
			stack_b->head->moves = stack_b->size - stack_b->head->order;
		else
			stack_b->head->moves = stack_a->head->order;
		// stack_b->head->moves = (stack_b->size - stack_b->head->order)
		// 	+ (stack_a->size - stack_a->head->order);
		// stack_b->head->direction = -1;
		stack_a->head->direction = -1;
	}
	else
	{
		stack_b->head->moves = (stack_b->size - stack_b->head->order)
			+ stack_a->head->order;
		// stack_b->head->direction = -1;
		stack_a->head->direction = 1;
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
		if (stack_b->head->order > (int)stack_b->size / 2)
			count_moves_btm(stack_a, stack_b);
		else
			count_moves_top(stack_a, stack_b);
		stack_a->head = fix_a;
		stack_b->head = stack_b->head->next;
	}
	stack_b->head = fix_b;
}

int	find_min_moves(t_stack *stack)
{
	t_elem	*fix;
	int		i;
	int		min_moves;
	
	fix = stack->head;
	i = stack->size - 1;
	min_moves = stack->head->moves;
	while (i--)
	{
		if (stack->head->next->moves < min_moves)
			min_moves = stack->head->next->moves;
		stack->head = stack->head->next;
	}
	stack->head = fix;
	return (min_moves);
}

void	set_direction(t_stack *stack_a, t_stack *stack_b)
{
	t_elem	*fix;
	int		i;

	fix = stack_a->head;
	i = stack_a->size;
	while (i--)
	{

	}
	stack_a->head = fix;
	fix = stack_b->head;
	i = stack_b->size;
	while (i--)
	{

	}
	stack_b->head = fix;
}

void	make_moves(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->min_moves = find_min_moves(stack_b);
	set_direction(stack_a, stack_b);
	// ft_printf("MIN MOVES = %d\n", stack_b->min_moves);
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
		set_order(stack_a);
		set_order(stack_b);
		find_min_of_max(stack_a, stack_b);
		set_moves(stack_a, stack_b);
		make_moves(stack_a, stack_b);
		if (!check_sort_stack(stack_a))
			ft_printf("\tSTACK_A IS SORTED\n\tSTACK_B SIZE = %d\n", stack_b->size);
		exit(0);
	}
	// if (!check_sort_stack(stack_a))
	// 	ft_printf("\tSTACK_A IS SORTED\n\tSTACK_B SIZE = %d\n", stack_b->size);
	// exit(0);
}

	// int fd1;
	// fd1 = open("numbers_b", O_RDWR | O_CREAT | O_APPEND, 0644);
	// ft_putstr_fd("STACK_B NUMBER = ", fd1);
	// ft_putnbr_fd(stack_b->head->index, fd1);
	// ft_putstr_fd("\n", fd1);
	// ft_putstr_fd("STACK_B ORDER = ", fd1);
	// ft_putnbr_fd(stack_b->head->order, fd1);
	// ft_putstr_fd("\n", fd1);

	// int fd2;
	// fd2 = open("moves", O_RDWR | O_CREAT | O_APPEND, 0644);
	// ft_putstr_fd("STACK_B ORDER = ", fd2);
	// ft_putnbr_fd(stack_b->head->order, fd2);
	// ft_putstr_fd("\n", fd2);
	// ft_putstr_fd("STACK_A ORDER = ", fd2);
	// ft_putnbr_fd(stack_a->head->order, fd2);
	// ft_putstr_fd("\n", fd2);
	// ft_putstr_fd("MOVES = ", fd2);
	// ft_putnbr_fd(stack_b->head->moves, fd2);
	// ft_putstr_fd("\n", fd2);
	// ft_putstr_fd("STACK_B DIRECTION = ", fd2);
	// ft_putnbr_fd(stack_b->head->direction, fd2);
	// ft_putstr_fd("\n", fd2);
	// ft_putstr_fd("STACK_A DIRECTION = ", fd2);
	// ft_putnbr_fd(stack_a->head->direction, fd2);
	// ft_putstr_fd("\n\n", fd2);

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
