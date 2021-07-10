#include "fdf.h"

static void	get_map_data_by_line(char **parsed_line,
							int *size,
							t_list **map_data)
{
	int		index;
	int		current_width;
	t_list	*new;

	index = -1;
	current_width = 0;
	while (parsed_line[++index])
	{
		new = ft_lstnew(new_data(parsed_line[index]));
		if (!new)
			terminate(ERR_MALLOC);
		new->next = (*map_data);
		(*map_data) = new;
		current_width++;
	}
	check_current_map_width(current_width, size);
}

void	read_map(const int fd, int *size, t_list **map_data)
{
	int		res;
	char	*line;
	char	**parsed_line;

	res = get_next_line(fd, &line);
	while (check_end_conditions(res, line))
	{
		parsed_line = ft_split(line, ' ');
		if (!parsed_line)
			terminate(ERR_MALLOC);
		safe_free((void **)&line);
		get_map_data_by_line(parsed_line, size, map_data);
		free_str_array(&parsed_line);
		size[MAP_HEIGHT]++;
		res = get_next_line(fd, &line);
	}
	if (!(*map_data))
		terminate(ERR_EMPTY_MAP);
}
