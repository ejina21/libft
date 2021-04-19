#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p;
	const char		*s;

	if (!dst && !src)
		return (0);
	p = (unsigned char *)dst;
	s = (const char *)src;
	if (src < dst)
	{
		while (len > 0)
		{
			p[len - 1] = s[len - 1];
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*p++ = *s++;
			len--;
		}
	}
	return (dst);
}
