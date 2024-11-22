/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhouj <helkhouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:18:04 by helkhouj          #+#    #+#             */
/*   Updated: 2024/11/22 16:11:54 by helkhouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static size_t	skip_whitespace(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\f')
		i++;
	return (i);
}

static int	check_overflow(int result, int digit, int sign)
{
	if (result > (INT_MAX - digit) / 10)
	{
		if (sign == 1)
			return (INT_MAX);
		return (INT_MIN);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		result;
	int		overflow;

	i = skip_whitespace(str);
	sign = 1;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		overflow = check_overflow(result, str[i] - '0', sign);
		if (overflow != 0)
			return (overflow);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
