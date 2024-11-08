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

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	while (len > 0)
	{
		if (s[len - 1] == (char)c)
			return ((char *)&s[len - 1]);
		len--;
	}
	if ((char)c == '\0')
		return ((char *)&s[len - 1]);
	return (NULL);
}
