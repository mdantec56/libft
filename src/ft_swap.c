#include "libft.h"

void	ft_swap(long *n1, long *n2)
{
	long temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
