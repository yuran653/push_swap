/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 03:15:30 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/28 17:05:01 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int ext)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(ext);
}

void	error_free_argv(int argc, char **argv, int ext)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	free_argv(argc, argv);
	exit(ext);
}

void	error_free_stack(t_stack *stack, int ext)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	free_stack(stack);
	exit(ext);
}

void	error_free_all(int argc, char **argv, t_stack *stack, int ext)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	free_argv(argc, argv);
	free_stack(stack);
	exit(ext);
}
