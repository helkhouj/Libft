/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhouj <helkhouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:35:56 by helkhouj          #+#    #+#             */
/*   Updated: 2024/11/22 13:54:34 by helkhouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed_str;
	
	if (!s1 || !set)
		return (NULL);

	start = 0;
	end = ft_strlen(s1); 

	while (s1[start] && is_in_set(s1[start], set))
		start++;
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	trimmed_str = (char *)malloc((end - start + 1) * sizeof(char));
	if (!trimmed_str)
		return (NULL);
	ft_memcpy(trimmed_str, s1 + start, end - start);
	trimmed_str[end - start] = '\0';

	return (trimmed_str);
}
