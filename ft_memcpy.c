#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t i = 0;
    unsigned char *d = (unsigned char *)dst;
    unsigned char *s = (const unsigned char *)src;

    while(i < n)
    {
        d[i] = s[i];
        i++;
    }
    return (dst);
}