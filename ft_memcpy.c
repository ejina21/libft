#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p;
	const char		*s;

	if (!dst && !src)
		return (0);
	p = (unsigned char *)dst;
	s = (const char *)src;
	while (n > 0)
	{
		*p++ = *s++;
		n--;
	}
	return (dst);
}
