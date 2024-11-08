/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhouj <helkhouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:29:49 by helkhouj          #+#    #+#             */
/*   Updated: 2024/11/06 13:32:35 by helkhouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
    void *ptr;
    size_t total_size = count * size;
    size_t i = 0;

    if(cout != 0 && (total_size / count) != size)
        return(NULL);

    ptr = malloc(total_size);
    if(!ptr)
        return(NULL);

    unsigned char *p = (unsigned char *)ptr;
    while(i < total_size)
    {
        ptr[i] = 0;
        i++;
    }
    return ptr;
}