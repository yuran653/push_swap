/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:52:03 by jgoldste          #+#    #+#             */
/*   Updated: 2022/02/22 01:15:59 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atoi_ps(char *arg, unsigned long long int *number)
{
	int						sign;
	
	sign = 1;
	while (*arg == ' ' || *arg == '\t' || *arg == '\n'
		|| *arg == '\v' || *arg == '\f' || *arg == '\r')
		arg++;
	if (*arg == '+' || *arg == '-')
	{
		if (*arg == '-')
			sign = -1;
		arg++;
	}
	while (*arg != '\0' && *arg >= '0' && *arg <= '9')
	{
		*number = *number * 10 + *arg - 48;
		arg++;
	}
	return (sign);
}

t_elem	*get_number(char *arg)
{
	int						sign;
	unsigned long long int	num;
	t_elem					*elem;

	num = 0;
	sign = atoi_ps(arg, &num);
	if (sign == -1 && num > 2147483648)
		return (NULL);
	if (sign == 1 && num > 2147483647)
		return (NULL);
	elem = init_element(sign * (int)num);
	if (!elem)
		return (NULL);
	return (elem);
}