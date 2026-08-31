#include "libft.h"

int	ft_get_oct(char *fichier)
{
	int	fd;
	int	nb_oct;
	int	oct_lus;
	char	buffer[1000];

	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		return (-1);
	oct_lus = read(fd, buffer, 999);
	nb_oct = 0;
	while (oct_lus > 0)
	{
		nb_oct += oct_lus;
		oct_lus = read(fd, buffer, 999);
	}
	close(fd);
	return (nb_oct);
}

char	*ft_get_strfic(char *fichier, int nb_oct)
{
	int	fd;
	char	*ficstr;
	int	tot_lus;
	int	oct_lus;

	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ficstr = malloc(sizeof(char) * (nb_oct + 1));
	if (!ficstr)
	{
		close(fd);
		return (NULL);
	}
	tot_lus = 0;
	while (tot_lus <= nb_oct)
	{
		oct_lus = read(fd, ficstr + tot_lus, nb_oct - tot_lus);
		if (oct_lus <= 0)
			break ;
		tot_lus += oct_lus;
	}
	ficstr[tot_lus] = '\0';
	close(fd);
	return (ficstr);
}

char	*ft_get_fichier(char *fichier)
{
	return (ft_get_strfic(fichier, ft_get_oct(fichier)));
}
