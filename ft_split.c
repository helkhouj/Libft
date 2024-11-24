/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhouj <helkhouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:33:12 by helkhouj          #+#    #+#             */
/*   Updated: 2024/11/23 15:19:38 by helkhouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static void	*free_all(char **result, size_t idx)
{
	while (idx--)
		free(result[idx]);
	free(result);
	return (NULL);
}

static char	**populate_result(char const *s, char c, char **result, size_t word_count)
{
	size_t	i;
	size_t	start;
	size_t	idx;

	i = 0;
	idx = 0;
	while (s[i] && idx < word_count)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i; 
		while (s[i] && s[i] != c)
			i++;

		if (i > start) 
		{
			result[idx] = ft_substr(s, start, i - start);
			if (!result[idx])
				return (free_all(result, idx));
			idx++;
		}
	}
	result[idx] = NULL; 
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;

	if (!s)
		return (ft_strdup("")); 
	word_count = count_words(s, c);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (populate_result(s, c, result, word_count));
}
