#include "libft.h"

int	ft_get_size(char **srcs)
{
	int	i;

	i = 0;
	while (srcs[i])
		++i;
	return (i);
}

int	ft_get_len(char **srcs, char *sep)
{
	int	len;
	int	lensep;
	int	i;

	lensep = ft_strlen(sep);
	len = - lensep;
	i = 0;
	while (srcs[i])
	{
		len += ft_strlen(srcs[i]) + lensep;
		++i;
	}
	return (len);
}

int	ft_putsep(char *sep, char *join, int debut)
{
	int	lensep;
	int	i;

	lensep = ft_strlen(sep);
	i = 0;
	while (i < lensep)
	{
		join[debut + i] = sep[i];
		++i;
	}
	return (debut + i);
}

int	ft_putstring(char **srcs, char *join, int ind, int debut)
{
	int	len;
	int	i;

	len = ft_strlen(srcs[ind]);
	i = 0;
	while (i < len)
	{
		join[debut + i] = srcs[ind][i];
		++i;
	}
	return (debut + i);
}

char	*ft_strjoin(char **srcs, char *sep)
{
	char	*join;
	int	len;
	int	i;
	int	j;

	if (!srcs || !sep)
		return (NULL);
	len = ft_get_len(srcs, sep);
	join = malloc(sizeof(char) * (len + 1));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		i = ft_putstring(srcs, join, j, i);
		++j;
		if (j < ft_get_size(srcs))
			i = ft_putsep(sep, join, i);
	}
	join[i] = '\0';
	return (join);
}
