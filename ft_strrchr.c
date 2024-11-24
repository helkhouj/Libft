/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhouj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:42:58 by helkhouj          #+#    #+#             */
/*   Updated: 2024/11/06 09:43:01 by helkhouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c) {
    size_t len = 0;
    ssize_t i;

    while (s[len])
        len++;

    i = len;
    while (i >= 0) {
        if (s[i] == (char)c)
            return ((char *)&s[i]);
        i--;
    }
    return (NULL);
}
