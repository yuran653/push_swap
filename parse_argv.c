/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:09:44 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/22 06:52:30 by jgoldste         ###   ########.fr       */
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
					error_free_stack(stack_a);
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

	i = 0;
	if (argc == 2)
		i--;
	stack_a = init_stack('a');
	if (!stack_a)
		error_free_argv(argc, argv);
	while (argv[++i])
	{
		elem = get_number(argv[i]);
		if (!elem)
			error_free_all(argc, argv, stack_a);
		append_stack(stack_a, elem);
		stack_a->size = i;
		if (argc == 2)
			stack_a->size = stack_a->size + 1;
	}
	return (stack_a);
}

int	check_digit(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		if (!ft_isdigit(arg[i]))
		{
			if ((arg[i] != '-' && arg[i] != '+') || i != 0)
				return (1);
			if ((arg[0] == '-' || arg[0] == '+') && ft_strlen(arg) == 1)
				return (1);
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
			error();
		i--;
	}
	while (argv[++i])
		if (check_digit(argv[i]))
			error_free_argv(argc, argv);
	stack_a = get_stack(argc, argv);
	free_argv(argc, argv);
	check_duplicate(stack_a);
	return (stack_a);
}
