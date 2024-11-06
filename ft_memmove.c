/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhouj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:50:05 by helkhouj          #+#    #+#             */
/*   Updated: 2024/11/06 12:50:08 by helkhouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d == 0 || s == 0)
		return (dst);
	if (d < s || d >= s + len)
		return (ft_memcpy(dst, src, len));
	while (len > 0)
	{
		len--;
		d[len] = s[len];
	}
	return (dst);
}
