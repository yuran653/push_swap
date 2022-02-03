/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:09:44 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/04 02:00:53 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	get_digit(char *arg, t_stacks *stacks)
{
	int	i;
	int	digit;

	i = -1;
	while (arg[++i])
		if (ft_isalpha(arg[i]) == 1)
			error_digit();
	digit = ft_atoi(arg);
	init_stack_a(stacks, init_element(digit));
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
		while (args_char[++i])
			get_digit(args_char[i], stacks);
	}
	else
	{
		i = 0;
		while (argv[++i])
			get_digit(argv[i], stacks);
	}
}
