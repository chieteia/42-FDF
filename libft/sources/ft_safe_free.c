#include "libft.h"

void	safe_free(void **p)
{
	if (*p != NULL)
	{
		free(*p);
		*p = NULL;
	}
}
