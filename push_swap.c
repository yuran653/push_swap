/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:21:16 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/04 03:56:07 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			stop;

	stacks = init_stacks();
	validation(argc, argv, stacks);
	stop = stacks->size_a;
	while (stop--)
	{
		printf("\t[%d]\n", stacks->head_a->digit);
		stacks->head_a = stacks->head_a->next;
	}
	return (0);
}
