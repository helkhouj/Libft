/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhouj <helkhouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:34:45 by helkhouj          #+#    #+#             */
/*   Updated: 2024/11/23 15:08:34 by helkhouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL); // TODO(XENOBAS): This is not easy to defend.
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	joined_str = (char *)malloc(total_len + 1);
	if (!joined_str)
		return (NULL);
	ft_memcpy(joined_str, s1, s1_len);
	ft_memcpy(joined_str + s1_len, s2, s2_len);
	joined_str[total_len] = '\0';
	return (joined_str);
}
