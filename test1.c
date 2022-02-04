/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 04:33:34 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/04 13:08:38 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

typedef struct s_elem
{
	int					number;
	struct s_elem	*next;
	struct s_elem	*prev;
}	t_elem;

typedef struct s_stacks
{
	t_elem			*head_a;
	t_elem			*head_b;
	unsigned int	size_a;
	unsigned int	size_b;
}	t_stacks;

t_elem	*init_element(int number)
{
	t_elem	*element;

	element = (t_elem *)malloc(sizeof(t_elem));
	if (!element)
		return (NULL);
	element->number = number;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

void	init_stack_a(t_stacks *stack, t_elem *element)
{
	t_elem	*tmp;

	tmp = stack->head_a;
	if (tmp)
	{
		if (tmp->prev)
		{
			element->next = tmp;
			element->prev = tmp->prev;
			tmp->prev->next = element;
			tmp->prev = element;
		}
		else
		{
			element->next = tmp;
			element->prev = tmp;
			tmp->next = element;
			tmp->prev = element;
		}
	}
	else
		stack->head_a = element;
}

void	init_stacks(t_stacks *stack)
{
	stack->head_a = NULL;
	stack->head_b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
}

int	main(void)
{
	t_stacks	stacks;
	t_elem		digit;
	int			arr[10] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
	int			i;

	i = -1;
	init_stacks(&stacks);
	while (++i < 10)
		init_stack_a(&stacks, init_element(arr[i]));
	i = -1;
	while (++i < 10)
	{
		printf("\t[%d]\n", stacks.head_a->number);
		stacks.head_a = stacks.head_a->next;
	}
	return (0);
}
