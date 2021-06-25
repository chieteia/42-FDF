#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (!ft_malloc((void **)&res, size, count))
		return (NULL);
	ft_memset(res, 0, size * count);
	return (res);
}
