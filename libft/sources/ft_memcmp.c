#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*dst;
	const unsigned char	*src;

	dst = (const unsigned char *)s1;
	src = (const unsigned char *)s2;
	while (n-- && (dst || src))
	{
		if (*dst != *src)
			return (*dst - *src);
		dst++;
		src++;
	}
	return (0);
}
