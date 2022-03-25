/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 23:01:55 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/25 04:38:09 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	swap_or_both(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	h;
// 	int	n;

// 	h = stack_b->head->index;
// 	n = stack_b->head->next->index;
// 	if (h < n)
// 		make_swap_both(stack_a, stack_b);
// 	else
// 		make_swap(stack_a);
// }

static void	insert_three_top(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	h;
	int	n;

	h = stack_b->head->index;
	n = stack_b->head->next->index;
	while (stack_b->head->index != value)
	{
		// make_rotate(stack_b);
		if (stack_b->head->index == value - 2)
		{
			make_push(stack_b, stack_a);
			make_rotate(stack_a);
		}
		if (stack_b->head->index == value - 1)
			make_push(stack_b, stack_a);
	}
	make_push(stack_b, stack_a);
	// swap_or_both(stack_a, stack_b);
	if (h < n)
		make_swap_both(stack_a, stack_b);
	else
		make_swap(stack_a);
	make_reverse(stack_a);
	if (stack_a->head->index == 100)
	{
		ft_printf("\t---WTF---\n");
		exit(0);
	}
}

static void	insert_two_top(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	h;
	int	n;

	h = stack_b->head->index;
	n = stack_b->head->next->index;
	while (stack_b->head->index != value - 1)
		make_rotate(stack_b);
	make_push(stack_b, stack_a);
	while (stack_b->head->index != value)
		make_rotate(stack_b);
	make_push(stack_b, stack_a);
	// swap_or_both(stack_a, stack_b);
	if (h < n)
		make_swap_both(stack_a, stack_b);
	else
		make_swap(stack_a);
}

int	find_top(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_elem	*fix;
	int		i;
	int		is_two;
	int		is_three;
	
	fix = stack_b->head;
	i = stack_b->size / 2 + stack_b->size % 2;
	is_two = 0;
	is_three = 0;
	while (i--)
	{
		if (stack_b->head->next->index == value - 1)
			is_two++;
		if (stack_b->head->prev->index == value - 2)
			is_three++;
		if (stack_b->head->next->index == value)
		{
			stack_b->head = fix;
			if (!is_two)
				return (1);
			else if (!is_three)
				insert_two_top(stack_a, stack_b, value);
			else
				insert_three_top(stack_a, stack_b, value);
			return (0);
		}
		stack_b->head = stack_b->head->next;
	}
	stack_b->head = fix;
	return (0);
}

static void	insert_three_btm(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	h;
	int	n;

	h = stack_b->head->index;
	n = stack_b->head->next->index;
	while (stack_b->head->index != value)
	{
		make_reverse(stack_b);
		if (stack_b->head->index == value - 2)
		{
			make_push(stack_b, stack_a);
			make_rotate(stack_a);
		}
		if (stack_b->head->index == value - 1)
			make_push(stack_b, stack_a);
	}
	make_push(stack_b, stack_a);
	// swap_or_both(stack_a, stack_b);
	if (h < n)
		make_swap_both(stack_a, stack_b);
	else
		make_swap(stack_a);
	make_reverse(stack_a);
}

static void	insert_two_btm(t_stack *stack_a, t_stack *stack_b, int value)
{
	int	h;
	int	n;

	h = stack_b->head->index;
	n = stack_b->head->next->index;
	while (stack_b->head->index != value - 1)
		make_reverse(stack_b);
	make_push(stack_b, stack_a);
	while (stack_b->head->index != value)
		make_reverse(stack_b);
	make_push(stack_b, stack_a);
	// swap_or_both(stack_a, stack_b);
	if (h < n)
		make_swap_both(stack_a, stack_b);
	else
		make_swap(stack_a);
}

int	find_btm(t_stack *stack_a, t_stack *stack_b, int value)
{
	t_elem	*fix;
	int		i;
	int		is_two;
	int		is_three;

	fix = stack_b->head;
	i = stack_b->size / 2;
	is_two = 0;
	is_three = 0;
	while (i--)
	{
		if (stack_b->head->prev->index == value - 1)
			is_two++;
		if (stack_b->head->prev->index == value - 2)
			is_three++;
		if (stack_b->head->prev->index == value)
		{
			stack_b->head = fix;
			if (!is_two)
				return (1);
			else if (!is_three)
				insert_two_btm(stack_a, stack_b, value);
			else
				insert_three_btm(stack_a, stack_b, value);
			return (0);
		}
		stack_b->head = stack_b->head->prev;
	}
	stack_b->head = fix;
	return (0);
}

static void	print_stack(t_stack *stack)
{
	t_elem	*fix;
	int		i;

	fix = stack->head;
	for (i = 1; i <= (int)stack->size; i++)
	{
		ft_printf("%d - STACK_B [%d]\n", i, stack->head->index);
		stack->head = stack->head->next;
	}
	stack->head = fix;
}

void	sort_insert(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size > 33)
	{
		ft_printf("HEAD A = %d\n", stack_a->head->index);
		ft_printf("HEAD B = %d = %d = VALUE\n",
			stack_b->head->index, stack_a->head->index - 1);
		if (stack_b->head->index == stack_a->head->index - 1)
			make_push(stack_b, stack_a);
		else if (find_top(stack_a, stack_b, stack_a->head->index - 1))
		{
			ft_printf("\t---HERE TOP---\n");
			while (stack_b->head->index != stack_a->head->index - 1)
				make_rotate(stack_b);
			make_push(stack_b, stack_a);
		}
		else if (find_btm(stack_a, stack_b, stack_a->head->index - 1))
		{
			ft_printf("\t---HERE BTM---\n");
			while (stack_b->head->index != stack_a->head->index - 1)
				make_reverse(stack_b);
			make_push(stack_b, stack_a);
		}
		print_stack(stack_b);
		ft_printf("SIZE_B = %d\n", stack_b->size);
		ft_printf("\t---HERE MAIN---\n");
	}
}
