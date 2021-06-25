#include "fdf.h"

void	check_map_value(char **parsed_str)
{
	if (!ft_isnumber(parsed_str[0], 10)
		|| (parsed_str[1] && !ft_isnumber(parsed_str[1], 16)))
		terminate(ERR_READ_MAP);
}

t_data	*get_map_data(char **parsed_str)
{
	t_data	*new;

	if(!ft_malloc((void **)&new, sizeof(t_data), 1))
		terminate(ERR_READ_MAP);
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

void	check_current_map_width(char **parsed_line, t_admin *master)
{
	int	index;
	int	current_width;

	index = -1;
	current_width = 0;
	while (parsed_line[++index])
		current_width++;
	if (master->map->height == 0)
		master->map->width = current_width;
	else if (master->map->width > current_width)
		terminate(ERR_MAP_COMPOSITION);
}

void	get_map_data_by_line(char **parsed_line,
							t_admin *master,
							t_list **map_data)
{
	int	index;

	index = -1;
	check_current_map_width(parsed_line, master);
	while (parsed_line[++index])
		ft_lstadd_back(map_data, ft_lstnew(new_data(parsed_line[index])));
	//ft_putstr_fd("\n", 2);
}

void	read_map(const int fd, t_admin *master, t_list **map_data)
{
	char	*line;
	char	**parsed_line;

	while (get_next_line(fd, &line) == 1)
	{
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
		get_map_data_by_line(parsed_line, master, map_data);
		free_str_array(&parsed_line);
		safe_free((void**)&line);
		master->map->height++;
	}
	if (!(*map_data))
		terminate(ERR_EMPTY_MAP);
}