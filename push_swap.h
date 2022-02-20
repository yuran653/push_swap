/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:19:29 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/20 06:04:49 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>

typedef struct s_elem
{
	int				number;
	struct s_elem	*next;
	struct s_elem	*prev;
}	t_elem;

typedef struct s_stack
{
	t_elem			*head;
	unsigned int	size;
}	t_stack;

t_stack			*validation(int argc, char **argv);
unsigned int	get_digit(char **argv, t_stack *stack_a, int free);
void			check_digit(char **argv, t_stack *stack_a, int free);
void			check_duplicate(t_stack *stack_a);
t_stack			*init_stack(void);
t_elem			*init_element(int number);
void			append_stack(t_stack *stack, t_elem *elem);
void			free_array(char **array);
void			free_stack(t_stack *stack);
void			error(void);
void			error_malloc(t_stack *stack);

#endif