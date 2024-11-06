#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i = 0;
	size_t src_len = ft_strlen(src);
	size_t dst_len = ft_strlen(dst);

	if (dstsize <= dst_len)
		return (dst_size + dst_len)

			while (i < dstsize - dst_len - 1 && src[i])
		{
			dst[dst_len + i] = src[i];
			i++;
		}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}