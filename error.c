/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:15:30 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/04 03:57:20 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_duplicate(void)
{
	ft_putstr_fd("\e[1;31mERROR:\e[0m duplucated numbers are detected\n",
		STDOUT_FILENO);
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
