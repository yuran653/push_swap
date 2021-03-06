/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:09:44 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/08 16:01:54 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort_int(int *unsort, int size)
{
	int		i;

	i = 0;
	while (i < size - 1)
	{
		if (unsort[i] > unsort[i + 1])
			return (1);
		else
			i++;
	}
	return (0);
}

void	check_duplicate(int *unsort, int size)
{
	int	i;
	int	j;

	i = -1;
	if (size > 1)
	{
		while (++i < size)
		{
			j = -1;
			while (++j < size)
			{
				if (unsort[i] == unsort[j] && i != j)
					free_array_exit(unsort, EXIT_SUCCESS, 1);
			}
		}
	}
}

t_stack	*get_stack(int argc, char **argv)
{
	int		size;
	int		*sort;
	int		*unsort;
	t_stack	*stack_a;

	size = array_size(argc, argv);
	unsort = (int *)malloc(sizeof(int) * size);
	if (!unsort)
		free_argv_exit(argc, argv, EXIT_FAILURE, 1);
	get_int_array(argc, argv, unsort);
	check_duplicate(unsort, size);
	if (!check_sort_int(unsort, size))
		free_array_exit(unsort, EXIT_SUCCESS, 0);
	sort = array_copy(unsort, size);
	stack_a = init_stack('a');
	if (!stack_a)
		free_array_exit(unsort, EXIT_FAILURE, 1);
	stack_a->size = size;
	fill_stack(stack_a, unsort, sort);
	return (stack_a);
}

int	check_digit(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
	{
		if (!ft_isdigit(arg[i]))
		{
			if ((arg[i] != '-' && arg[i] != '+') || i != 0)
				return (1);
			if ((arg[0] == '-' || arg[0] == '+') && ft_strlen(arg) == 1)
				return (1);
		}
	}
	return (0);
}

t_stack	*validation(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;

	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			exit_error(EXIT_FAILURE, 1);
		i--;
	}
	while (argv[++i])
		if (check_digit(argv[i]))
			free_argv_exit(argc, argv, EXIT_SUCCESS, 1);
	stack_a = get_stack(argc, argv);
	return (stack_a);
}
