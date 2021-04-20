#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!p)
		return (p);
	i = 0;
	while (*s1)
	{
		p[i] = *s1;
		i++;
		s1++;
	}
	p[i] = 0;
	return (p);
}
