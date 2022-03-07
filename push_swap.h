/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:19:29 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/07 18:15:14 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdarg.h>

#include <stdio.h>

typedef struct s_elem
{
	int				number;
	int				index;
	struct s_elem	*next;
	struct s_elem	*prev;
}	t_elem;

typedef struct s_stack
{
	t_elem			*head;
	unsigned int	size;
	int				min;
	int				max;
	char			name;
}	t_stack;

t_stack	*validation(int argc, char **argv);
int		check_digit(char *arg);
t_stack	*get_stack(int argc, char **argv);
int		array_size(int argc, char **argv);
void	get_int_array(int argc, char **argv, int *unsort);
int		atoi_ps(char *arg, unsigned long long int *number);
void	check_duplicate(int *unsort, int size);
int		check_sort_int(int *unsort, int size);
int		check_sort_stack(t_stack *stack);
int		*array_copy(int *src, int size);
t_stack	*init_stack(char name);
t_elem	*init_element(int number, int index);
void	fill_stack(t_stack *stack, int *unsort, int* sort);
void	append_stack(t_stack *stack, t_elem *elem);
void	make_swap(t_stack *stack);
void	make_swap_both(t_stack *stack_a, t_stack *stack_b);
void	make_rotate(t_stack *stack);
void	make_rotate_both(t_stack *stack_a, t_stack *stack_b);
void	make_reverse(t_stack *stack);
void	make_reverse_both(t_stack *stack_a, t_stack *stack_b);
void	make_push(t_stack *stack_src, t_stack *stack_dst);
void	add_stack(t_stack *stack_dst, t_elem *elem);
void	free_argv_exit(int argc, char **argv, int ext, int err);
void	free_array_exit(int *array, int ext, int err);
void	free_array2_exit(int *array1, int *array2, int ext, int err);
void	free_stack_exit(t_stack *stack, int ext, int err);
void	exit_error(int ext, int err);
int		ft_printf(const char *str, ...);
void	sort(t_stack *stack_a, t_stack *stack_b);
void	sort_next(t_stack *stack_a, t_stack *stack_b);
void	sort_insert(t_stack *stack_a, t_stack *stack_b);

#endif