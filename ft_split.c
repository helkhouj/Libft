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

static size_t count_words(const char *s, char c)
{
    size_t count = 0;
    int in_word = 0;

    while (*s)
    {
        if(*s != c && !in_word)
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

static char *word_dup(const char *s, size_t start, size_t len)
{
    char *word = (char *)malloc((len + 1) * sizeof(char));
    size_t i = 0;
    if(!word)
        return(NULL);
    while (i < len)
    {
        word[i] = s[start + i];
        i++;
    }
    word[len] = '\0';
    return word;
}

static void free_split(char **result, size_t index)
{
    while(index > 0)
        free(result[--index]);
    free(result);
}

char	**ft_split(char const *s, char c)
{
    
}