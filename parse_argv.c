/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:09:44 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/20 21:57:34 by jgoldste         ###   ########.fr       */
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

int	check_digit(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		if (!ft_isdigit(arg[i]))
			return (1);
	return (0);
}

// void	check_int(int number, t_stack *stack_a, int free_arr)
// {

// }

t_stack	*get_stack(int argc, char **argv)
{
	int		i;
	int		number;
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
		number = ft_atoi(argv[i]);
		// check_int(number, stack_a, free_arr);
		elem = init_element(number);
		if (!elem)
			error_malloc(stack_a);
		append_stack(stack_a, elem);
	}
	if (argc != 2)
		i--;
	stack_a->size = i;
	free_argv(argc, argv);
	return (stack_a);
}

t_stack	*validation(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;

	i = 0;
	if (argc == 1)
		exit(EXIT_SUCCESS);
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
	check_duplicate(stack_a);
	return (stack_a);
}
