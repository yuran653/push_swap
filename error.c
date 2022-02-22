/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:15:30 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/22 01:47:01 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	error_free_argv(int argc, char **argv)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	free_argv(argc, argv);
	exit(EXIT_FAILURE);
}

void	error_free_stack(t_stack *stack)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

void	error_free_all(int argc, char **argv, t_stack *stack)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	free_argv(argc, argv);
	free_stack(stack);
	exit(EXIT_FAILURE);
}