/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:52:03 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/21 21:56:22 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atoi_ps(char *arg, unsigned long long int *number)
{
	int	sign;

	sign = 1;
	while (*arg == ' ' || *arg == '\t' || *arg == '\n'
		|| *arg == '\v' || *arg == '\f' || *arg == '\r')
		arg++;
	if (*arg == '+' || *arg == '-')
	{
		if (*arg == "-")
			sign = -1;
		arg++;
	}
	while (*arg != '\0' && *arg >= '0' && *arg <= '9')
	{
		number = number * 10 + *arg - 48;
		arg++;
	}
	return (sign);
}

t_elem	*get_number(int argc, char **argv)
{
	int						i;
	unsigned long long int	number;
	t_elem					*elem;

	number = 0;
	i = -1;
	while (argv[++i])
		number = atoi_ps(argv[i], &number);
	if (number < -2147483647 || number > 2147483648)
		return (NULL);
	elem = init_element((int)number);
	if (!elem)
		return (NULL);
	return (elem);
}