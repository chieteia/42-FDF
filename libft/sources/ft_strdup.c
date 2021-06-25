#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;

	if (!(ft_malloc((void **)&res, sizeof(char), ft_strlen(s1) + 1)))
		return (NULL);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	return (res);
}
