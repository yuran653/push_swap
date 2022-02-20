/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 03:20:56 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/19 07:01:59 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_rra(t_stacks *stacks, int rrr)
{
	if (stacks->size_a > 1)
		stacks->head_a = stacks->head_a->prev;
	if (rrr != 1)
		write(1, "rra\n", 4);
}

void	make_rrb(t_stacks *stacks, int rrr)
{
	if (stacks->size_b > 1)
		stacks->head_b = stacks->head_b->prev;
	if (rrr != 1)
		write(1, "rrb\n", 4);
}

void	make_rrr(t_stacks *stacks)
{
	make_rra(stacks, 1);
	make_rrb(stacks, 1);
	write(1, "rrr\n", 4);
}