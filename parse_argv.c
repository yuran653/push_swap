/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:09:44 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/04 13:07:38 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	check_duplicate(t_stacks *stacks)
{
	int	stop1;
	int	stop2;
	int	compare;

	stop1 = stacks->size_a;
	while (stop1 > 0)
	{
		compare = stacks->head_a->number;
		stop2 = stacks->size_a - 1;
		while (stop2 > 0)
		{
			if (compare == stacks->head_a->next->number)
				error_duplicate(stacks);
			stacks->head_a = stacks->head_a->next;
			stop2--;
		}
		stacks->head_a = stacks->head_a->next->next;
		stop1--;
	}
}

void	get_digit(char *arg, t_stacks *stacks)
{
	int		i;
	int		number;
	t_elem	*elem;

	i = -1;
	while (arg[++i])
		if (ft_isalpha(arg[i]) == 1)
			error_digit();
	number = ft_atoi(arg);
	elem = init_element(number);
	// free(elem);
	// elem = NULL;
	if (!elem)
		error_malloc(stacks);
	init_stack_a(stacks, elem);
}

void	validation(int argc, char **argv, t_stacks *stacks)
{
	char	**args_char;
	int		i;

	if (argc == 1)
		error_args();
	if (argc == 2)
	{
		i = -1;
		args_char = ft_split(argv[1], ' ');
		if (!args_char)
			error_malloc(stacks);
		while (args_char[++i])
			get_digit(args_char[i], stacks);
		free_array(args_char);
	}
	else
	{
		i = 0;
		while (argv[++i])
			get_digit(argv[i], stacks);
		i--;
	}
	stacks->size_a = (unsigned int)i;
	check_duplicate(stacks);
}
