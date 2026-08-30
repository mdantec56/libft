#include "libft.h"

void	ft_toupper(char c)
{
	if (ft_islow(c))
		c -= 32;
}
