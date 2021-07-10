#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*res;

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
