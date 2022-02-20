/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:21:16 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/20 03:01:52 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stacks(t_stacks *stacks)
{
	int	stop;
	int	stop_a;
	int	stop_b;

	printf("\t------STACK A------\t------STACK B------\n");
	stop_a = stacks->size_a;
	stop_b = stacks->size_b;
	if (stop_a >= stop_b)
		stop = stop_a;
	else
		stop = stop_b;
	if (stop)
	{
		while (stop--)
		{
			if (stop_a)
			{
				printf("\t\t[%d]", stacks->head_a->number);
				stacks->head_a = stacks->head_a->next;
				stop_a--;
			}
			else
				printf("\t\t[EMPTY]\n");
			if (stop_b)
			{
				printf("\t\t\t[%d]\n", stacks->head_b->number);
				stacks->head_b = stacks->head_b->next;
				stop_b--;
			}
			else
				printf("\t\t\t[EMPTY]\n");
		}
		if (stacks->size_a)
			printf("\n\tHEAD_A\t[%d]", stacks->head_a->number);
		if (stacks->size_b)
			printf("\t\tHEAD_B\t[%d]", stacks->head_b->number);
		printf("\n");
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	
	stacks = init_stacks();
	if (!stacks)
		error_init();
	validation(argc, argv, stacks);
	print_stacks(stacks);
	make_sa(stacks, 0);
	print_stacks(stacks);
	// make_sb(stacks, 0);
	// print_stacks(stacks);
	// make_ss(stacks);
	// print_stacks(stacks);
	// make_ra(stacks, 0);
	// print_stacks(stacks);
	// make_rb(stacks, 0);
	// print_stacks(stacks);
	// make_rr(stacks);
	// print_stacks(stacks);
	// make_rra(stacks, 0);
	// print_stacks(stacks);
	// make_rrb(stacks, 0);
	// print_stacks(stacks);
	// make_rrr(stacks);
	// print_stacks(stacks);
	free_stacks(stacks);
	return (0);
}
