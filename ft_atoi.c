#include "libft.h"

int	ft_atoi(const char *str)
{
	int			flag;
	long int	sum;

	flag = 0;
	sum = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			flag = !flag;
	while (*str >= '0' && *str <= '9')
	{
		if (sum >= 922337203685477580 && *str - '0' > 7)
			return (- !flag);
		sum = sum * 10 + *str - '0';
		str++;
	}
	if (flag)
		return (-sum);
	else
		return (sum);
}
