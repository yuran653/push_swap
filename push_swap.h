/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:19:29 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/04 04:04:56 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_element
{
	int					digit;
	struct s_element	*next;
	struct s_element	*prev;
}	t_elem;

typedef struct s_stacks
{
	t_elem			*head_a;
	t_elem			*head_b;
	unsigned int	size_a;
	unsigned int	size_b;
}	t_stacks;

void		validation(int argc, char **argv, t_stacks *stacks);
void		get_digit(char *arg, t_stacks *stacks);
t_stacks	*init_stacks(void);
t_elem		*init_element(int number);
void		init_stack_a(t_stacks *stacks, t_elem *elem);
void		check_duplicate(t_stacks *stacks);
void		error_args(void);
void		error_digit(void);
void		error_duplicate(void);

#endif