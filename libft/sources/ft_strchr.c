#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
		{
			res = (char *)&(*s);
			break ;
		}
		s++;
	}
	return (res);
}
