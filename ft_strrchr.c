#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			p = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (p);
}
