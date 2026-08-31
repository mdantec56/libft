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
	return (nb_oct);
}

char	*ft_get_strfic(char *fichier, int nb_oct)
{
	int	fd;
	char	*ficstr;
	char	buffer[2];
	int	i;

	i = 0;
	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ficstr = malloc(sizeof(char) * (nb_oct + 1));
	if (!ficstr)
		return (NULL);
	read(fd, buffer, 1);
	while (i < nb_oct)
	{
		ficstr[i] = buffer[0];
		buffer[1] = '\0';
		read(fd, buffer, 1);
		++i;
	}
	ficstr[i] = '\0';
	return (ficstr);
}

char	*ft_get_fichier(char *fichier)
{
	return (ft_get_strfic(fichier, ft_get_oct(fichier)));
}
