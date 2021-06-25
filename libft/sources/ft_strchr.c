#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	while (i < (int)ft_strlen(s) + 1)
	{
		if (!s)
			return (NULL);
		if (s[i] == c)
		{
			res = (char *)&s[i];
			break ;
		}
		i++;
	}
	return (res);
}
