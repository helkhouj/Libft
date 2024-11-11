/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helkhouj <helkhouj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:33:12 by helkhouj          #+#    #+#             */
/*   Updated: 2024/11/06 13:33:44 by helkhouj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*word_dup(const char *s, size_t start, size_t len)
{
	char	*word;
	size_t	i;

	word = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	free_split(char **result, size_t index)
{
	while (index > 0)
		free(result[--index]);
	free(result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	size_t	words_index;
	size_t	word_count;
	size_t	word_start;
	size_t	word_len;

	i = 0;
	words_index = 0;
	word_start = 0;
	word_len = 0;
	if (!s || !(result = malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (NULL);
	word_count = count_words(s, c);
	while (s[i])
	{
		if (s[i] != c && word_len++ == 0)
			word_start = i;
		else if ((s[i] == c || s[i + 1] == '\0') && word_len)
		{
			if (!(result[word_index++] = word_dup(s, word_start, word_len)))
				return (free_split(result, word_index - 1), NULL);
			word_len = 0;
		}
		i++;
	}
	result[word_index] = NULL;
	return (result);
}
