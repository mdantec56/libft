#include "libft.h"

int	ft_is_sep(char *str, char *substring, int indc)
{
	int	i;
	int	count_sep;
	int	len_substr;

	i = 0;
	count_sep = 0;
	len_substr = ft_strlen(substring);
	while (i < len_substr && str[indc + i])
	{
		if (str[indc + i] == substring[i])
			++count_sep;
		++i;
	}
	if (count_sep == i && substring[i] == '\0')
		return (1);
	return (0);
}

int	ft_count_words(char *str, char *substring)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_is_sep(str, substring, i))
			i += ft_strlen(substring);
		else
		{
			++count;
			while (str[i] && !ft_is_sep(str, substring, i))
				++i;
		}
	}
	return (count);
}

char	*ft_newstring(char *str, int debut, int fin)
{
	char	*newstring;
	int	i;

	i = 0;
	newstring = malloc(sizeof(char) * (fin - debut + 1));
	if (!newstring)
		return (NULL);
	while (i < fin - debut)
	{
		newstring[i] = str[debut + i];
		++i;
	}
	newstring[i] = '\0';
	return (newstring);
}

char	**ft_subsplit(char *str, char *substring)
{
	char	**splitted;
	int	count;
	int	i;
	int	debut;

	splitted = malloc(sizeof(char *) * (ft_count_words(str, substring) + 1));
	if (!splitted)
		return (NULL);
	i = 0;
	count = 0;
	while (count < ft_count_words(str, substring))
	{
		if (ft_is_sep(str, substring, i))
			i += ft_strlen(substring);
		else
		{
			debut = i;
			while (str[i] && !ft_is_sep(str, substring, i))
				++i;
			splitted[count] = ft_newstring(str, debut, i);
			++count;
		}
	}
	splitted[count] = NULL;
	return (splitted);
}
