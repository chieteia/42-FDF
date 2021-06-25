#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		size1;
	int		size2;

	if (!(s1 || s2))
		return ((char *)0);
	if (!s1)
		size1 = 0;
	else
		size1 = ft_strlen(s1);
	if (!s2)
		return ((char *)s1);
	size2 = ft_strlen(s2);
	if (!(ft_malloc((void **)&res, sizeof(char), size1 + size2 + 1)))
		return (NULL);
	*res = 0;
	ft_strlcat(res, (char *)s1, size1 + 1);
	ft_strlcat(res, (char *)s2, size1 + size2 + 1);
	return (res);
}
