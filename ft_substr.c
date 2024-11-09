/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhouj <helkhouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:36:30 by helkhouj          #+#    #+#             */
/*   Updated: 2024/11/06 13:36:52 by helkhouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    char *sub_str;
    size_t str_len;
    size_t actual_len;

    if(!s)
        return(NULL);

    str_len = ft_strlen(s);

    if(start >= str_len)
        return (char *)malloc(1);

    actual_len = str_len - start;

    if(actual_len > len)
        actual_len = len;

    sub_str = (char *)malloc(actual_len + 1);
    if(!sub_str)
        return(NULL);
    
    ft_memcpy(sub_str, s + start, actual_len);
    sub_str[actual_len] = '\0';
    return sub_str;
}