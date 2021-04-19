#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*p;
	const char		*s;

	p = (unsigned char *)dst;
	s = (const char *)src;
	while (n > 0)
	{
		*p = *s;
		if (*p == (unsigned char)c)
			return (++p);
		s++;
		p++;
		n--;
	}
	return (0);
}
