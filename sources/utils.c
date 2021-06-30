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
		terminate(ERR_READ_MAP);
	return (parsed_line);
}

int	count_word(const char *s, char c)
{
	int	word_counter;

	word_counter = 0;
	while (*s)
	{
		if (*s != c)
			word_counter++;
		while (*s != c && *s)
			s++;
		while (*s == c)
			s++;
	}
	return (word_counter);
}