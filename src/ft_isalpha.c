#include "libft.h"

int	ft_isalpha(char c)
{
	if (ft_isup(c) || ft_islow(c))
		return (1);
	return (0);
}
