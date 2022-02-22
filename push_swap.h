/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:19:29 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/22 06:57:09 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

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
	char			name;
}	t_stack;

t_stack	*validation(int argc, char **argv);
t_stack	*get_stack(int argc, char **argv);
int		check_digit(char *arg);
t_elem	*get_number(char *arg);
int		atoi_ps(char *arg, unsigned long long int *number);
void	check_duplicate(t_stack *stack_a);
t_stack	*init_stack(char name);
t_elem	*init_element(int number);
void	append_stack(t_stack *stack, t_elem *elem);
void	make_swap(t_stack *stack, char chr);
void	make_swap_both(t_stack *stack_a, t_stack *stack_b);
void	make_rotate(t_stack *stack, char chr);
void	make_rotate_both(t_stack *stack_a, t_stack *stack_b);
void	make_reverse(t_stack *stack, char chr);
void	make_reverse_both(t_stack *stack_a, t_stack *stack_b);
void	make_push(t_stack *stack_src, t_stack *stack_dst);
void	free_argv(int argc, char **argv);
void	free_stack(t_stack *stack);
void	error(void);
void	error_free_argv(int argc, char **argv);
void	error_free_stack(t_stack *stack);
void	error_free_all(int argc, char **argv, t_stack *stack);
int		ft_printf(const char *str, ...);

#endif