/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:09:44 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/21 22:02:28 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(t_stack *stack_a)
{
	int	stop1;
	int	stop2;
	int	compare;

	stop1 = stack_a->size;
	if (stop1 > 1)
	{
		while (stop1 > 0)
		{
			compare = stack_a->head->number;
			stop2 = stack_a->size - 1;
			while (stop2 > 0)
			{
				if (compare == stack_a->head->next->number)
					error_malloc(stack_a);
				stack_a->head = stack_a->head->next;
				stop2--;
			}
			stack_a->head = stack_a->head->next->next;
			stop1--;
		}
	}
}

t_stack	*get_stack(int argc, char **argv)
{
	int		i;
	t_elem	*elem;
	t_stack	*stack_a;

	i = -1;
	if (argc != 2)
		i++;
	stack_a = init_stack();
	if (!stack_a)
		error();
	while (argv[++i])
	{
		elem = get_number(argv);
		if (!elem)
		{
			free_argv(argc, argv);
			error_malloc(stack_a);
		}
		append_stack(stack_a, elem);
	}
	if (argc != 2)
		i--;
	stack_a->size = i;
	return (stack_a);
}

int	check_digit(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		if (!ft_isdigit(arg[i]))
			if ((arg[i] != '-' && arg[i] != '+') || i != 0)
				return (1);
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
			error();
		i--;
	}
	while (argv[++i])
	{
		if (check_digit(argv[i]))
		{
			free_argv(argc, argv);
			error();
		}
	}
	stack_a = get_stack(argc, argv);
	free_argv(argc, argv);
	check_duplicate(stack_a);
	return (stack_a);
}
