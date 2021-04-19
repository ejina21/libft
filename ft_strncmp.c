#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*r;

	i = 0;
	s = (unsigned char *)s1;
	r = (unsigned char *)s2;
	while ((*s || *r) && i < n)
	{
		if (*s != *r)
			return (*s - *r);
		s++;
		r++;
		i++;
	}
	return (0);
}
