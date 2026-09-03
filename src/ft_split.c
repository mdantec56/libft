#include "libft.h"

int	ft_is_sep2(char *sep, char c)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c || c == '\0')
			return (1);
		++i;
	}
	return (0);
}

int	ft_count_words2(char *str, char *charset)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (str[i - 1])
	{
		if (ft_is_sep2(charset, str[i]) && !ft_is_sep2(charset, str[i - 1]))
			++count;
		++i;
	}
	return (count);
}

char	*ft_new_string2(char *str, int debut, int fin)
{
	char	*newstr;
	int	i;

	i = 0;
	newstr = malloc(sizeof(char) * (fin - debut + 1));
	if (!newstr)
		return (NULL);
	while (i < fin - debut)
	{
		newstr[i] = str[debut + i];
		++i;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	**ft_split(char *str, char *charset)
{
	char	**splitted;
	int	count;
	int	i;
	int	debut;
	int	nb_words;

	i = 0;
	count = 0;
	debut = 0;
	nb_words = ft_count_words2(str, charset);
	splitted = malloc(sizeof(char *) * (nb_words + 1));
	if (!splitted)
		return (NULL);
	while (count < nb_words)
	{
		if (!ft_is_sep2(charset, str[i]) && (i == 0 || ft_is_sep2(charset, str[i - 1])))
			debut = i;
		if ((i == 0 || !ft_is_sep2(charset, str[i - 1])) && ft_is_sep2(charset, str[i]))
		{
			splitted[count] = ft_new_string2(str, debut, i);
			++count;
		}
		++i;
	}
	splitted[count] = NULL;
	return (splitted);
}
