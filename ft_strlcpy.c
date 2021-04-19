#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s;

	if (!src)
		return (0);
	s = ft_strlen(src);
	if (!dst || !dstsize)
		return (s);
	i = 0;
	while (i < dstsize - 1 && *src)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = 0;
	return (s);
}
