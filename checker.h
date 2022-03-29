/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 00:12:12 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/29 16:16:56 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "./get_next_line/get_next_line.h"

void	read_operation(t_stack *stack_a, t_stack *stack_b);
void	execute_operation(t_stack *stack_a, t_stack *stack_b, char *operation);
void	error_operation(t_stack *stack_a, t_stack *stack_b, char *operation);

#endif