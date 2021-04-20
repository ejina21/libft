#include "libft.h"

static int	count(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	j = len - 1;
	if (j < 0)
		return (0);
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	len -= i;
	i = 0;
	while (ft_strchr(set, s1[j]) && j != 0)
	{
		j--;
		i++;
	}
	len -= i;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		i;
	int		l;

	if (!s1)
		return (0);
	l = count(s1, set);
	if (l <= 0)
	{
		p = (char *)malloc(1);
		if (!p)
			return (0);
		p[0] = 0;
		return (p);
	}
	p = (char *)malloc(l + 1);
	if (!p)
		return (p);
	i = 0;
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	while (i < l)
		p[i++] = *s1++;
	p[i] = 0;
	return (p);
}
