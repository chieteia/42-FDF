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

//char	**parsed_by_char(char *line, char c)
//{
//	char	**parsed_line;

//	parsed_line = ft_split(line, c);
//	if (!parsed_line)
//		terminate(ERR_MALLOC);
//	return (parsed_line);
//}

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

int	default_color(int z, t_map *map)
{
	float	percent;

	percent = get_percent(map->z_min, map->z_max, z);
	if (percent < 0.15)
		return (PURPLE);
	else if (percent < 0.25)
		return (RIGHT_PURPLE);
	else if (percent < 0.35)
		return (BLUE);
	else if (percent < 0.5)
		return (RIGHT_BLUE);
	else if (percent < 0.7)
		return (GREEN);
	else if (percent < 0.75)
		return (YELLOW);
	else if (percent < 0.8)
		return (ORANGE);
	else if (percent < 0.9)
		return (PINK);
	else
		return (RIGHT_RED);
}

void	terminate(char *s)
{
	ft_putstr_fd(s, 2);
	exit(0);
}
