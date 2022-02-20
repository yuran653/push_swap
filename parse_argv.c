/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:09:44 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/20 06:29:55 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(t_stack *stack_a)
{
	int	stop1;
	int	stop2;
	int	compare;

	stop1 = stack_a->size;
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

void	check_digit(char **argv, t_stack *stack_a, int free)
{
	int	i;
	int	j;

	i = -1;
	if (!free)
		i++;
	j = -1;
	while (argv[++i])
	{
		while (argv[i][++j])
			if (ft_isalpha(argv[i][j]) == 1)
			{
				if (free)
					free_array(argv);
				error_malloc(stack_a);
			}
	}
}

unsigned int	get_digit(char **argv, t_stack *stack_a, int free)
{
	int		size;
	int		number;
	t_elem	*elem;

	size = -1;
	if (!free)
		size++;
	while (argv[++size])
	{
		check_digit(argv, stack_a, free);
		number = ft_atoi(argv[size]);
		elem = init_element(number);
		if (!elem)
			error_malloc(stack_a);
		append_stack(stack_a, elem);
	}
	if (!free)
		size--;
	return ((unsigned int)size);
}

t_stack	*validation(int argc, char **argv)
{
	char	**args_char;
	t_stack	*stack_a;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	stack_a = init_stack();
	// if (!stack_a)
	// 	error();
	printf("\t\targc = %d\n---CHECK0---\n", argc);
	if (argc == 2)
	{
		printf("---CHECK1---\n");
		args_char = ft_split(argv[1], ' ');
		if (!args_char)
			error_malloc(stack_a);
		stack_a->size = get_digit(args_char, stack_a, 1);
		free_array(args_char);
	}
	else
	{
		printf("---CHECK2---");
		// stack_a->size = get_digit(argv, stack_a, 0);
	}
	printf("---CHECK3---\n");
	check_duplicate(stack_a);
	return (stack_a);
}
