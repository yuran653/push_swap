/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:07:29 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/24 19:59:34 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <fcntl.h>

void	print_value(t_stack *stack)
{
	t_elem	*fix;
	int		i;

	i = stack->size;
	fix = stack->head;
	while (i--)
	{
		ft_printf("ORDER_%c = %d INDEX = %d MIN_OF_MAX = %d MOVES = %d DIRECTION = %d\n",
			stack->name, stack->head->order, stack->head->index, stack->head->min_of_max,
			stack->head->moves, stack->head->direction);
		stack->head	= stack->head->next;	
	}
	stack->head = fix;
}

int	set_min_of_max(t_stack *stack_a, t_stack *stack_b)
{
	t_elem	*fix;
	int		i;
	int		min_of_max;

	
	i = stack_a->size;
	min_of_max = stack_a->total;
	fix = stack_a->head;
	while (i--)
	{
		if (stack_b->head->index < stack_a->head->index)
		{
			if (min_of_max > stack_a->head->index)
				min_of_max = stack_a->head->index;
		}
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
	
	i = stack_b->size;
	fix = stack_b->head;
	while (i--)
	{
		stack_b->head->min_of_max = set_min_of_max(stack_a, stack_b);
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
		stack->head->order = 0;
		fix = stack->head;
		while (i--)
		{
			stack->head->next->order = stack->head->order + 1;
			stack->head = stack->head->next;
		}
		stack->head = fix;
	}
}

int	set_min_moves(t_stack *stack)
{
	t_elem	*fix;
	int		i;
	int		min_moves;
	
	i = stack->size - 1;
	min_moves = stack->head->moves;
	fix = stack->head;
	while (i--)
	{
		if (stack->head->next->moves < min_moves)
			min_moves = stack->head->next->moves;
		stack->head = stack->head->next;
	}
	stack->head = fix;
	return (min_moves);
}

static void	count_moves_top(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->head->direction = 1;
	if (stack_a->head->order > (int)stack_a->size / 2)
	{
		stack_b->head->moves = stack_b->head->order
			+ (stack_a->size - stack_a->head->order);
		stack_a->head->direction = -1;
	}
	else
	{
		if (stack_b->head->order > stack_a->head->order)
			stack_b->head->moves = stack_b->head->order;
		else
			stack_b->head->moves = stack_a->head->order;
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
		stack_b->head->moves = stack_a->size - stack_a->head->order;
		stack_a->head->direction = -1;
	}
	else
	{
		stack_b->head->moves = (stack_b->size - stack_b->head->order)
			+ stack_a->head->order;
		stack_a->head->direction = 1;
	}
}

void	set_moves(t_stack *stack_a, t_stack *stack_b)
{
	t_elem	*fix_a;
	t_elem	*fix_b;
	int		i;

	i = stack_b->size;
	fix_b = stack_b->head;
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

int	set_direction_a(t_stack *stack_a, int *min_of_max)
{
	t_elem	*fix;
	int		i;
	int		index;

	i = stack_a->size;
	fix = stack_a->head;
	while (i--)
	{
		if (stack_a->head->index == *min_of_max)
		{
			stack_a->direction = stack_a->head->direction;
			index = stack_a->head->index;
			stack_a->head = fix;
			return (index);
		}
		stack_a->head = stack_a->head->next;
	}
	stack_a->head = fix;
	return (-1);
}

int	set_direction_b(t_stack *stack_b, int *min_of_max)
{
	t_elem	*fix;
	int		i;
	int		index;

	fix = stack_b->head;
	i = stack_b->size;
	while (i--)
	{
		if (stack_b->head->moves == stack_b->min_moves)
		{
			stack_b->direction = stack_b->head->direction;
			*min_of_max = stack_b->head->min_of_max;
			index = stack_b->head->index;
			stack_b->head = fix;
			return (index);
		}
		stack_b->head = stack_b->head->next;
	}
	stack_b->head = fix;
	return (-1);
}

void	make_moves_unidir(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->direction > 0)
	{
		while (stack_a->head->index != stack_a->index
			&& stack_b->head->index != stack_b->index)
			make_rotate_both(stack_a, stack_b);
		while (stack_a->head->index != stack_a->index)
			make_rotate(stack_a);
		while (stack_b->head->index != stack_b->index)
			make_rotate(stack_b);
		make_push(stack_b, stack_a);
	}
	else
	{
		while (stack_a->head->index != stack_a->index
			&& stack_b->head->index != stack_b->index)
			while (stack_a->head->index != stack_a->index
			&& stack_b->head->index != stack_b->index)
			make_reverse_both(stack_a, stack_b);
		while (stack_a->head->index != stack_a->index)
			make_reverse(stack_a);
		while (stack_b->head->index != stack_b->index)
			make_reverse(stack_b);
		make_push(stack_b, stack_a);
	}
}

void	make_moves_multidir(t_stack *stack)
{
	if (stack->direction > 0)
		while (stack->head->index != stack->index)
			make_rotate(stack);
	else
		while (stack->head->index != stack->index)
			make_reverse(stack);		
}

void	make_moves(t_stack *stack_a, t_stack *stack_b)
{
	int	min_of_max;
	
	stack_b->min_moves = set_min_moves(stack_b);
	stack_b->index = set_direction_b(stack_b, &min_of_max);
	stack_a->index = set_direction_a(stack_a, &min_of_max);
	if (stack_a->direction == stack_b->direction)
		make_moves_unidir(stack_a, stack_b);
	else
	{
		make_moves_multidir(stack_a);
		make_moves_multidir(stack_b);
		make_push(stack_b, stack_a);
	}

	// ft_printf("MIN_MOVES = %d\n", stack_b->min_moves);
	// ft_printf("INDEX_A = %d MIN_OF_MAX = %d DIRECTION_A = %d\n",
	// 	stack_a->index, min_of_max, stack_a->direction);
	// print_value(stack_a);
	// ft_printf("\n");
	// ft_printf("INDEX_B = %d DIRECTION_B = %d\n",
	// 	stack_b->index, stack_b->direction);
	// print_value(stack_b);
	// if (!check_sort_stack(stack_a))
	// 	ft_printf("\tSTACK_A IS SORTED\n\tSTACK_B SIZE = %d\n", stack_b->size);
	// exit(0);
}

void	check_order(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->head->order)
	{
		ft_printf("ORDER_A = %d\n", stack_a->head->order);
		ft_putstr_fd("---ORDER ERROR---\n", 2);
		exit(0);
	}
	if (stack_b->head->order)
	{
		ft_printf("ORDER_B = %d\n", stack_b->head->order);
		ft_putstr_fd("---ORDER ERROR---\n", 2);
		exit(0);
	}
}

void	sort_insert(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size)
	{
		// while (stack_b->head->index < stack_a->head->index
		// 	|| (stack_b->head->index < stack_a->head->next->index
		// 	&& stack_b->head->index > stack_a->head->index))
		// 	{
		// 		make_push(stack_b, stack_a);
		// 		if (stack_a->head->index > stack_a->head->next->index)
		// 			make_swap(stack_a);
		// 	}
		set_order(stack_a);
		set_order(stack_b);
		check_order(stack_a, stack_b);
		find_min_of_max(stack_a, stack_b);
		set_moves(stack_a, stack_b);
		// print_value(stack_a);
		// print_value(stack_b);
		make_moves(stack_a, stack_b);
		// print_value(stack_a);
		// print_value(stack_b);
		// if (!check_sort_stack(stack_a))
		// 	ft_printf("\tSTACK_A IS SORTED\n\tSTACK_B SIZE = %d\n", stack_b->size);
		// exit(0);
	}
	// while (stack_a->head->index != 1)
	// 	make_reverse(stack_a);
	// if (!check_sort_stack(stack_a))
	// 	ft_printf("\tSTACK_A IS SORTED\n\tSTACK_B SIZE = %d\n", stack_b->size);
	// ft_printf("\t\t---EXIT---\n");
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
