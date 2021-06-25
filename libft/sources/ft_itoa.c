#include "libft.h"

static int	ft_size(int n)
{
	int	size;

	size = 1;
	size += (n < 0);
	while (n / 10)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	tmp;
	int		size;
	char	*ascii;

	tmp = n;
	size = ft_size(n);
	if (!(ft_malloc((void **)&ascii, sizeof(char), size + 1)))
		return (NULL);
	ascii[size--] = '\0';
	if (tmp == 0)
		ascii[0] = '0';
	if (tmp < 0)
	{
		ascii[0] = '-';
		tmp *= -1;
	}
	while (tmp)
	{
		ascii[size--] = tmp % 10 + '0';
		tmp /= 10;
	}
	return (ascii);
}
