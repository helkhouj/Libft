/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhouj <helkhouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:33:56 by helkhouj          #+#    #+#             */
/*   Updated: 2024/11/21 18:09:08 by helkhouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char *))
{
    unsigned int i;

    if (!s || !f)
        return;

    i = 0;
    while (s[i])
    {
        f(i, &s[i]);
        i++;
    }
}

void ft_upper(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

int main(void)
{
    char str[] = "hello";
    ft_striteri(str, ft_upper);
    printf("%s", str);
    return 0;
}
