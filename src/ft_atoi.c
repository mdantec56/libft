#include "libft.h"

long	ft_atoi(char *str)
{
	long	res;
	int	i;
	long	signe;

	i = 0;
	res = 0;
	signe = 1;
	while (str[i] == '-')
	{
		signe = signe * -1;
		++i;
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			res = res * 10 + (str[i] - '0');
		else
			return (-1);
		++i;
	}
	return (res * signe);
}
