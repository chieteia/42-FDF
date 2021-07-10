#include "fdf.h"

void	free_str_array(char ***array)
{
	int		index;
	char	**tmp;

	index = 0;
	tmp = *array;
	while (tmp[index])
		safe_free((void **)&tmp[index++]);
	free(*array);
	*array = NULL;
}

void	terminate(char *s)
{
	ft_putstr_fd(s, 2);
	exit(0);
}
