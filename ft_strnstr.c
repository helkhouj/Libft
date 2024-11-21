d/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhouj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:43:47 by helkhouj          #+#    #+#             */
/*   Updated: 2024/11/06 09:43:50 by helkhouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);

	i = 0;
	while (i < len && haystack[i])
	{
		j = 0;
		while (i + j < len && haystack[i + j] && haystack[i + j] == needle[j])
		{
			j++;
			if (!needle[j])
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

int main (void)
{
	const char *haystack = "hello, world!";
	const char *needle = "w";
	size_t len = 20;
	
	printf("%s\n", ft_strnstr(haystack, needle, len));
	return 0;
}
