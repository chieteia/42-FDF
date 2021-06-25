#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*res;
	const unsigned char	*sr;

	res = (unsigned char *)dst;
	sr = (unsigned char *)src;
	while (n--)
	{
		*res = *sr;
		if (*sr == (unsigned char)c)
			return (res + 1);
		res++;
		sr++;
	}
	return (NULL);
}
