#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t len = 0;
	while (s[len])
		len++;

	while (len > 0)
	{
		if (s[len - 1] == (char)c)
			return ((char *)&s[len - 1]);
		len--;
	}
	if ((char)c == '\0')
		return ((char *)&s[len - 1]);

	return (NULL);
}