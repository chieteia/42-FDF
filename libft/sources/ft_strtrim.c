#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		l;
	int		charset[300];

	if (!(s1 && set))
		return (NULL);
	i = 0;
	while (i < 300)
		charset[i++] = 0;
	while (*set)
		charset[(int)*set++]++;
	while (*s1 && charset[(int)*s1])
		s1++;
	l = ft_strlen(s1);
	while (l && charset[(int)s1[l - 1]])
		l--;
	if (!(ft_malloc((void **)&res, sizeof(char), l + 1)))
		return (NULL);
	ft_strlcpy(res, s1, l + 1);
	return (res);
}
