#include "libft.h"

long	ft_partition(long *tab, long low, long high)
{
	int	i;
	int	j;
	long	pivot;

	pivot = tab[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (tab[j] < pivot)
		{
			++i;
			ft_swap(&tab[i], &tab[j]);
		}
		++j;
	}
	ft_swap(&tab[i + 1], &tab[high]);
	return (i + 1);
}

void	ft_quicksort(long *tab, long low, long high)
{
	long	pivot_index;

	if (low < high)
	{
		pivot_index = ft_partition(tab, low, high);
		ft_quicksort(tab, low, pivot_index - 1);
		ft_quicksort(tab, pivot_index + 1, high);
	}
}
