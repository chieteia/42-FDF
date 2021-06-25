#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*res;
	const char	*sr;

	res = (char *)dest;
	sr = (const char *)src;
	if (!(dest || src))
		return (NULL);
	while (n--)
	{
		*res = *sr;
		res++;
		sr++;
	}
	return (dest);
}
