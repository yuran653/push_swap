/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 03:17:22 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/20 04:06:48 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_sa(t_stacks *stacks, int ss)
{
	t_elem	*tmp1;
	t_elem	*tmp2;

	if (stacks->size_a > 1)
	{
		tmp1 = stacks->head_a;
		tmp2 = stacks->head_a->next;
		stacks->head_a->next->next->prev = tmp1;
		tmp1->next = stacks->head_a->next->next;
		tmp2->next = tmp1;
		tmp2->prev = stacks->head_a->prev;
		stacks->head_a->prev->next = tmp2;
		tmp1->prev = tmp2;
		stacks->head_a = tmp2;
	}
	if (ss != 1)
			write(1, "sa\n", 3);
}

void	make_sb(t_stacks *stacks, int ss)
{
	t_elem	*tmp1;
	t_elem	*tmp2;

	if (stacks->size_b > 1 && stacks->head_b)
	{
		tmp1 = stacks->head_b;
		tmp2 = stacks->head_b->next;
		stacks->head_b->next->next->prev = tmp1;
		tmp1->next = stacks->head_b->next->next;
		tmp2->next = tmp1;
		tmp2->prev = stacks->head_b->prev;
		stacks->head_b->prev->next = tmp2;
		tmp1->prev = tmp2;
		stacks->head_b = tmp2;
	}
	if (ss != 1)
			write(1, "sb\n", 3);
}

void	make_ss(t_stacks *stacks)
{
	make_sa(stacks, 1);
	make_sb(stacks, 1);
	write(1, "ss\n", 3);
}