/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:52:03 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/06 18:13:09 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	array_size(int argc, char **argv)
{
	int	size;

	size = 0;
	while (argv[size])
		size++;
	if (argc != 2)
		size--;
	return (size);
}

int	atoi_ps(char *arg, unsigned long long int *number)
{
	int	sign;

	sign = 1;
	while (*arg == ' ' || *arg == '\t' || *arg == '\n'
		|| *arg == '\v' || *arg == '\f' || *arg == '\r')
		arg++;
	if (*arg == '+' || *arg == '-')
	{
		if (*arg == '-')
			sign = -1;
		arg++;
	}
	while (*arg != '\0' && *arg >= '0' && *arg <= '9')
	{
		*number = *number * 10 + *arg - 48;
		arg++;
	}
	return (sign);
}

void	get_int_array(int argc, char **argv, int *unsort)
{
	int						i;
	int						j;
	int						sign;
	unsigned long long int	num;

	i = 0;
	if (argc == 2)
		i--;
	j = 0;
	while (argv[++i])
	{
		num = 0;
		sign = atoi_ps(argv[i], &num);
		if (sign == -1 && num > 2147483648)
			free_argv_exit(argc, argv, EXIT_SUCCESS, 1);
		if (sign == 1 && num > 2147483647)
			free_argv_exit(argc, argv, EXIT_SUCCESS, 1);
		unsort[j++] = sign * num;
	}
	free_argv_exit(argc, argv, -1, 0);
}
