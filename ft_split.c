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

static int	help(char const *s, char c)
{
	if (*s != c)
		return (1);
	else
		return (0);
}

static int	len_word(char const *s, char c, int i)
{
	int	flag;
	int	count;
	int	len;

	flag = 0;
	count = help(s, c);
	len = 0;
	while (*s++)
	{
		while (*s == c && *s++)
			flag = 1;
		if (flag && *s)
		{
			flag = 0;
			count++;
		}
		if (count == i + 1)
			return (len);
		if (!(*s))
			break ;
		len++;
	}
	return (0);
}

static int	freem(char **p, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(p[j++]);
	if (i > 0)
		free(p);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		count;
	int		i[2];

	if (!s)
		return (0);
	count = count_word(s, c);
	p = malloc(sizeof(char *) * (count + 1));
	if (!p)
		return (p);
	i[0] = 0;
	while (i[0] < count)
	{
		p[i[0]] = malloc(len_word(s, c, i[0]) + 1);
		if (!p[i[0]] && freem(p, i[0]))
			return (p);
		while (*s == c && *s)
			s++;
		i[1] = 0;
		while (*s != c && *s)
			p[i[0]][i[1]++] = *s++;
		p[i[0]++][i[1]] = 0;
	}
	p[i[0]] = 0;
	return (p);
}
