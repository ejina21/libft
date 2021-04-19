#include "libft.h"

static char	*help(const char *haystack, const char *needle,
		size_t len, size_t i)
{
	size_t	j;
	char	*p;

	p = 0;
	if (*haystack == *needle && (len - i) >= ft_strlen(needle))
	{
		j = 1;
		p = (char *)haystack;
		while (j < ft_strlen(needle))
		{
			if (*(++haystack) == needle[j])
				j++;
			else
			{
				p = 0;
				haystack--;
				break ;
			}
		}
		if (p)
			return (p);
	}
	return (p);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*p;

	p = 0;
	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (*haystack && i < len)
	{
		p = help(haystack, needle, len, i);
		if (p)
			return (p);
		i++;
		haystack++;
	}
	return (p);
}
