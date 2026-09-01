#include "libft.h"

char	*ft_itoa(long nbr)
{
	char	*str;
	int	i;
	long	n;
	int	len;

	n = nbr;
	len = 0;
	while (n > 0)
	{
		n = n / 10;
		++len;
	}
	str = malloc(sizeof(char) * (len + 1));
	n = nbr;
	i = len - 1;
	while (i >= 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		--i;
	}
	str[len] = '\0';
	return (str);
}
