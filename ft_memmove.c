#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
    unsigned char *d = (unsigned char *)dst;
    unsigned char *s = (const unsigned char *)src;

    if (d == 0 || s == 0)
        return(dst);

    if (d < s || d >= s + len)
        return (ft_memcpy(dst, src, len));
    
    while(len > 0)
    {
        len--;
        d[len] = s[len];
    }
    return(dst);
}