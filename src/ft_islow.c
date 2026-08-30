#include "libft.h"

int	ft_islow(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}
