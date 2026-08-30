int	ft_isup(char c);
int	ft_islow(char c);

int	ft_isalpha(char c)
{
	if (ft_isup(c) || ft_islow(c))
		return (1);
	return (0);
}
