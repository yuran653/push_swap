/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 01:20:51 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/22 06:55:22 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_recurs_nbr(long long num, int *count)
{
	long long	num_write;

	if (num > 0)
	{
		ft_recurs_nbr(num / 10, count);
		num_write = num % 10 + 48;
		*count += write(1, &num_write, 1);
	}
}

void	ft_recurs_hex(unsigned long long num, char type, int *count)
{
	unsigned long long	num_write;
	int					type_hex;

	if (type == 'X')
		type_hex = 55;
	if (type == 'x' || type == 'p')
		type_hex = 87;
	if (num > 0)
	{
		ft_recurs_hex(num / 16, type, count);
		num_write = num % 16;
		if (num_write <= 9)
			num_write = num_write + 48;
		else
			num_write = num_write + type_hex;
		*count += write(1, &num_write, 1);
	}
}

void	ft_putnbrhex_pf(long long num, char type, int *count)
{
	if (type == 'd' || type == 'i' || type == 'u')
	{
		if (num == 0)
			*count += write(1, "0", 1);
		if (num > 0)
			ft_recurs_nbr(num, count);
		if (num < 0)
		{
			*count += write(1, "-", 1);
			num *= -1;
			ft_recurs_nbr(num, count);
		}
	}
	if (type == 'p')
		num = (unsigned long long)num;
	if (type == 'x' || type == 'X' || type == 'p')
	{
		if (type == 'p')
			*count += write(1, "0x", 2);
		if (num == 0)
			*count += write(1, "0", 1);
		else
			ft_recurs_hex(num, type, count);
	}
}

void	ft_print_arg(va_list args, char type, int *count)
{
	char	s;
	char	*str;

	if (type == 'c')
	{
		s = va_arg(args, int);
		*count += write(1, &s, 1);
	}
	else if (type == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
			*count += write(1, "(null)", 6);
		else
			while (*str && str != NULL)
				*count += write(1, str++, 1);
	}
	else if (type == 'd' || type == 'i')
		ft_putnbrhex_pf(va_arg(args, int), type, count);
	else if (type == 'u' || type == 'x' || type == 'X')
		ft_putnbrhex_pf(va_arg(args, unsigned int), type, count);
	else if (type == 'p')
		ft_putnbrhex_pf(va_arg(args, unsigned long long), type, count);
	else
		*count += write(1, &type, 1);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			str++;
			ft_print_arg(args, *str, &count);
		}
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (count);
}
