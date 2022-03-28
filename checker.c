/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:10:58 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/26 00:38:37 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = validation(argc, argv);
	stack_b = init_stack('b');
	if (!stack_b)
		exit_error(EXIT_FAILURE, 1);
	if (stack_a->size > 1)
	{
		ft_printf("CHECKER\n");
	}
	free_stack_exit(stack_a, -1, 0);
	free_stack_exit(stack_b, -1, 0);
	return (0);
}
