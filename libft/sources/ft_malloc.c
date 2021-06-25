#include "libft.h"

bool	ft_malloc(void **str, size_t sz, size_t len)
{
	*str = malloc(sz * len);
	return (!!*str);
}
