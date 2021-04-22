#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	flag;
	int	count;

	flag = 0;
	if (*s != c)
		count = 1;
	else
		count = 0;
	while (*s)
	{
		while (*s == c && *s)
		{
			flag = 1;
			s++;
		}
		if (flag && *s)
		{
			flag = 0;
			count++;
		}
		if (!(*s))
			break ;
		s++;
	}
	return (count);
}

static int	len_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s == c && *s)
		s++;
	while (*s != c && *s)
	{
		i++;
		s++;
	}
	return (i);
}

static int	freem(char **p, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(p[j]);
		j++;
	}
	free(p);
	return (1);
}

static const char	*skip(char const *s, char c)
{
	while (*s == c && *s)
		s++;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		i;
	int		l;

	if (!s)
		return (0);
	p = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!p)
		return (p);
	i = 0;
	s = skip(s, c);
	while (*s)
	{
		l = len_word(s, c);
		p[i] = ft_substr(s, 0, l);
		if (!p[i] && freem(p, i))
			return (p);
		s += l;
		i++;
		s = skip(s, c);
	}
	p[i] = 0;
	return (p);
}
