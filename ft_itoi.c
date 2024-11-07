/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhouj <helkhouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:18:47 by helkhouj          #+#    #+#             */
/*   Updated: 2024/11/06 14:25:13 by helkhouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_itoa(int n)
{
    int len = get_num_length(n);
    int sign = 1;
    char *str;

    if (n < 0)
        sign = -1;

    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return NULL;

    str[len] = '\0';
    if (n == 0)
    {
        str[0] = '0';
        return str;
    }

    while (n != 0)
    {
        str[--len] = (sign * (n % 10)) + '0';
        n /= 10;
    }

    if (sign == -1)
        str[0] = '-';

    return str;
}

