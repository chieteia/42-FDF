#include "fdf.h"

void	check_map_value(char **parsed_str)
{
	if (!ft_isnumber(parsed_str[0], 10)
		|| (parsed_str[1] && !ft_isnumber(parsed_str[1], 16)))
		terminate(ERR_INCORRECT_MAP);
}

t_data	*get_map_data(char **parsed_str)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		terminate(ERR_MALLOC);
	//if(!ft_malloc((void **)&new, sizeof(t_data), 1))
	//	terminate(ERR_MALLOC);
	new->z = ft_atoi(parsed_str[0]);
	if (parsed_str[1])
		new->color = ft_atoi_base(parsed_str[1], 16);
	else
		new->color = -1;
	return (new);
}

t_data	*new_data(char *str)
{
	t_data	*new;
	char	**parsed_str;

	//ft_putstr_fd("a", 2);
	//ft_putstr_fd(str, 2);
	//ft_putstr_fd(" ", 2);
	parsed_str = parsed_by_char(str, ',');
	//ft_putstr_fd("b", 2);
	//ft_putstr_fd(str, 2);
	check_map_value(parsed_str);
	new = get_map_data(parsed_str);
	free_str_array(&parsed_str);
	return (new);
}

void	check_current_map_width(char **parsed_line, int *size)
{
	int	index;
	int	current_width;

	index = -1;
	current_width = 0;
	while (parsed_line[++index])
		current_width++;
	if (size[MAP_HEIGHT] == 0)
		size[MAP_WIDTH] = current_width;
	else if (size[MAP_WIDTH] > current_width)
		terminate(ERR_INCORRECT_MAP);
}

void	get_map_data_by_line(char **parsed_line,
							int *size,
							t_list **map_data)
{
	int		index;
	t_list	*new;

	index = -1;
	new = NULL;
	check_current_map_width(parsed_line, size);
	while (parsed_line[++index])
	{
		new = ft_lstnew(new_data(parsed_line[index]));
		if (!new)
			terminate(ERR_MALLOC);
		ft_lstadd_back(map_data, new);
	}
	//ft_putstr_fd("\n", 2);
}

void	 read_map(const int fd, int *size, t_list **map_data)
{
	int		res;
	char	*line;
	char	**parsed_line;

	res = 1;
	while (res)
	{
		res = get_next_line(fd, &line);
		if (res < 0)
			terminate(ERR_READ_MAP);
		if (res == 0 && !*line)
			break;
		//ft_putstr_fd(line, 2);
		//ft_putchar_fd('\n', 2);
		//int index = 0;
		parsed_line = parsed_by_char(line, ' ');
		//while (parsed_line[index])
		//{
		//	ft_putstr_fd(parsed_line[index], 2);
		//	ft_putchar_fd(',', 2);
		//	index++;
		//}
		//ft_putchar_fd('\n', 2);
		get_map_data_by_line(parsed_line, size, map_data);
		free_str_array(&parsed_line);
		safe_free((void**)&line);
		size[MAP_HEIGHT]++;
	}
	if (!(*map_data))
		terminate(ERR_EMPTY_MAP);
}