/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:15:30 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/04 13:03:24 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_init(void)
{
	ft_putstr_fd("\e[1;31mERROR:\e[0m malloc allocation error\n",
		STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

void	error_malloc(t_stacks *stacks)
{
	ft_putstr_fd("\e[1;31mERROR:\e[0m malloc allocation error\n",
		STDOUT_FILENO);
	free_stacks(stacks);
	while(1);
	exit(EXIT_FAILURE);
}

void	error_duplicate(t_stacks *stacks)
{
	ft_putstr_fd("\e[1;31mERROR:\e[0m duplucated numbers are detected\n",
		STDOUT_FILENO);
	free_stacks(stacks);
	exit(EXIT_SUCCESS);
}

void	error_digit(void)
{
	ft_putstr_fd("\e[1;31mERROR:\e[0m not a number is received as an argument\n",
		STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}

void	error_args(void)
{
	ft_putstr_fd("\e[1;31mERROR:\e[0m no arguments are received\n", STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}
