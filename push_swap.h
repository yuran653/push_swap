/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:19:29 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/19 06:58:36 by jgoldste         ###   ########.fr       */
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
void		make_sa(t_stacks *stacks, int ss);
void		make_sb(t_stacks *stacks, int ss);
void		make_ss(t_stacks *stacks);
void		make_ra(t_stacks *stacks, int rr);
void		make_rb(t_stacks *stacks, int rr);
void		make_rr(t_stacks *stacks);
void		make_rra(t_stacks *stacks, int rrr);
void		make_rrb(t_stacks *stacks, int rrr);
void		make_rrr(t_stacks *stacks);
void		error_args(void);
void		error_digit(void);
void		error_duplicate(t_stacks *stacks);
void		error_malloc(t_stacks *stacks);
void		error_init(void);
void		free_array(char **array);
void		free_stacks(t_stacks *stacks);

#endif