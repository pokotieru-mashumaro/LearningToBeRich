int	ft_isalpha(int c)
{
	if (65 <= c && c <= 90)
		return (1);
	if (97 <= c && c <= 122)
		return (1);
	return (0);
}
