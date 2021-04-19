#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s;
	size_t	d;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (dstsize > d)
	{
		i = d;
		while (*src && i < dstsize - 1)
		{
			dst[i] = *src;
			i++;
			src++;
		}
		dst[i] = 0;
		dstsize = d;
	}
	return (s + dstsize);
}
