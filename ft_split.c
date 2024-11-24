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

// NOTE(XENOBAS): Avoid pointer iteration like the plague.
static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

// TODO(XENOBAS): You already have substr.
static char	*alloc_word(const char *s, size_t start, size_t len)
{
	char	*word;

	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_memcpy(word, s + start, len);
	word[len] = '\0';
	return (word);
}

static void	*free_all(char **result, size_t idx)
{
	while (idx--)
		free(result[idx]);
	free(result);
	return (NULL);
}

static char	**populate_result(char const *s, char c, char **result,
		size_t word_count)
{
	size_t	i;
	size_t	start;
	size_t	len;
	size_t	idx;

	i = 0;
	len = 0;
	idx = 0;
	while (s[i] && idx < word_count)
	{
		if (s[i] != c && len++ == 0)
			start = i;
		if ((s[i] == c || !s[i + 1]) && len > 0)
		{
			result[idx] = alloc_word(s, start, len);
			if (!result[idx])
				return (free_all(result, idx));
			idx++;
			len = 0;
		}
		i++;
	}
	result[idx] = NULL; // TODO(XENOBAS): Separate between 0 vs NULL vs '\0' !!!
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;

	if (!s)
		return (NULL); // TODO(XENOBAS): Hard to defend.
	word_count = count_words(s, c);
	result = malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (populate_result(s, c, result, word_count));
}
