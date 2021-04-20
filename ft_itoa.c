#include "libft.h"

static int	count(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	abs1(int n)
{
	int	i;

	i = n % 10;
	if (i > 0)
		return (i);
	else
		return (-i);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		len;

	len = 0;
	if (n < 0)
		len = 1;
	len += count(n);
	p = (char *)malloc(len + 1);
	if (!p)
		return (p);
	p[len] = 0;
	if (n < 0)
		p[0] = '-';
	if (n == 0)
		p[0] = '0';
	while (n != 0)
	{
		p[len - 1] = abs1(n) + '0';
		n /= 10;
		len--;
	}
	return (p);
}
