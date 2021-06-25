#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (!(dst || src))
		return (NULL);
	d = (char *)dst;
	s = (const char *)src;
	if (s <= d)
		while (len--)
			*(d + len) = *(s + len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
