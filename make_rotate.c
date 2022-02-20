/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 03:20:50 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/19 06:10:29 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_ra(t_stacks *stacks, int rr)
{
	if (stacks->size_a > 1)
		stacks->head_a = stacks->head_a->next;
	if (rr != 1)
		write(1, "ra\n", 3);
}

void	make_rb(t_stacks *stacks, int rr)
{
	if (stacks->size_b > 1)
		stacks->head_b = stacks->head_b->next;
	if (rr != 1)
		write(1, "rb\n", 3);
}

void	make_rr(t_stacks *stacks)
{
	make_ra(stacks, 1);
	make_rb(stacks, 1);
	write(1, "rr\n", 3);
}
