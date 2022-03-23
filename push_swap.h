/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 01:19:29 by jgoldste          #+#    #+#             */
/*   Updated: 2022/03/23 17:35:24 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdarg.h>

typedef struct s_elem
{
	int				number;
	int				index;
	int				order;
	int				min_of_max;
	int				moves;
	int				direction;
	struct s_elem	*next;
	struct s_elem	*prev;
}	t_elem;

typedef struct s_stack
{
	t_elem			*head;
	unsigned int	size;
	int				min;
	int				mid;
	int				max;
	int				min_moves;
	int				direction;
	int				total;
	char			name;
}	t_stack;

t_stack	*validation(int argc, char **argv);
int		check_digit(char *arg);
void	check_duplicate(int *unsort, int size);
int		check_sort_int(int *unsort, int size);
void	get_int_array(int argc, char **argv, int *unsort);
int		atoi_ps(char *arg, unsigned long long int *number);
int		array_size(int argc, char **argv);
int		*array_copy(int *src, int size);
t_stack	*get_stack(int argc, char **argv);
t_stack	*init_stack(char name);
t_elem	*init_element(int number, int index);
void	append_stack(t_stack *stack, t_elem *elem);
void	fill_stack(t_stack *stack, int *unsort, int *sort);
void	make_push(t_stack *stack_src, t_stack *stack_dst);
void	make_rotate(t_stack *stack);
void	make_rotate_both(t_stack *stack_a, t_stack *stack_b);
void	make_reverse(t_stack *stack);
void	make_reverse_both(t_stack *stack_a, t_stack *stack_b);
void	make_swap(t_stack *stack);
void	make_swap_both(t_stack *stack_a, t_stack *stack_b);
void	sort(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack);
void	sort_upto_five(t_stack *stack_a, t_stack *stack_b);
void	sort_more_five(t_stack *stack_a, t_stack *stack_b);
void	divide_stack(t_stack *stack_src, t_stack *stack_dst);
void	quarter_stack_a(t_stack *stack_a, t_stack *stack_b);
void	quarter_stack_b(t_stack *stack_b, t_stack *stack_a);
void	set_min_mid_max(t_stack *stack);
int		check_max_top(t_stack *stack);
int		check_max_btm(t_stack *stack);
int		check_min_top(t_stack *stack, int value);
int		check_min_btm(t_stack *stack, int value);
int		check_sort_stack(t_stack *stack);
void	sort_insert(t_stack *stack_a, t_stack *stack_b);
int		find_top(t_stack *stack_a, t_stack *stack_b, int value);
int		find_btm(t_stack *stack_a, t_stack *stack_b, int value);
void	exit_error(int ext, int err);
void	free_array_exit(int *array, int ext, int err);
void	free_array2_exit(int *array1, int *array2, int ext, int err);
void	free_argv_exit(int argc, char **argv, int ext, int err);
void	free_stack_exit(t_stack *stack, int ext, int err);
int		ft_printf(const char *str, ...);

#endif