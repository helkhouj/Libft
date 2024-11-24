/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhouj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:42:30 by helkhouj          #+#    #+#             */
/*   Updated: 2024/11/06 09:42:36 by helkhouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c) {
    size_t i = 0;

    while (s[i]) {
        if (s[i] == (char)c)
            return ((char *)&s[i]);
        i++;
    }

    if ((char)c == '\0')
        return ((char *)&s[i]);

    return (NULL);
}