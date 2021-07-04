#include "libft.h"

void	safe_free(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}
