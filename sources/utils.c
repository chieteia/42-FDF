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

char	**parsed_by_char(char *line, char c)
{
	char	**parsed_line;

	parsed_line = ft_split(line, c);
	if (!parsed_line)
		terminate("oppai");
	return (parsed_line);
}
