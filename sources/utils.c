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
		terminate(ERR_MALLOC);
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

int	default_color(int z, t_map *map)
{
	float	percent;

	//ratio = get_ratio_of_abs(z, map->z_min, map->z_max);
	//if (z < 0)
	//	return (get_cold_color(ratio));
	//else if (z > 0)
	//	return (get_warm_color(ratio));
	//else
	//	return (WHITE);
	percent = get_percent(map->z_min, map->z_max, z);
	if (percent < 0.25)
		return (0x392270);
	else if (percent < 0.5)
		return (0x5de8e5);
	else if (percent < 0.75)
		return (0xf44d9b);
	else
		return (0xe9275b);
}