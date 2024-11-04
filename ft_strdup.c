#include "libft.h"

char    *ft_strdup(const char *s)
{
    size_t len = 0;
    char *dup;

    while(s[len])
        len++;
    
    dup = (char *)malloc((len + 1) * sizeof(char));
    if(!dup)
        return(NULL);

    size_t i = 0;
    while(i < len)
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return(dup); 
}