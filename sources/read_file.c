#include "fdf.h"

float	get_ratio_of_abs(int num, int min, int max)
{
	if (num < 0)
		return ((float)num / min);
	else if (num > 0)
		return ((float)num / max);
	return (0);
	//position = current - start;
	//range = end - start;
	//return ((range == 0) ? 1.0 : (position / range));
}

//int gnl_check(int fd, char **line)
//{
//	int res;

//	res = get_next_line(fd, line);
//	if (res > 0)
//		return (1);
//	if (res < 0)
//		terminate(ERR_READ_MAP);
//	if (res == 0 && **line)
//		return (1);
//	else
//		return (0);
//}

void	check_map_form(t_map *map)
{
	int		fd;
	int		res;
	int		cnt;
	char	*line;

	if (map->height == 0 || map->width == 0)
		terminate(ERR_INCORRECT_MAP);
	fd = open(map->name, O_RDONLY);
	if (fd < 0)
		terminate(ERR_OPEN_FILE);
	while (1)
	{
		res = get_next_line(fd, &line);
		if (res < 0)
			terminate(ERR_READ_MAP);
		if (res == 0 && !*line)
			break;
		cnt = count_word(line, ' ');
		printf("cnt : %d\n", cnt);
		printf("line : %s\n", line);
		if (map->width != cnt)
			terminate(ERR_INCORRECT_MAP);
		safe_free((void**)&line);
	}
	safe_free((void**)&line);
	close(fd);
}

int get_height(char *file_name)
{
	int		fd;
	int		res;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		terminate(ERR_OPEN_FILE);
	height = 0;
	while (1)
	{
		res = get_next_line(fd, &line);
		if (res < 0)
			terminate(ERR_READ_MAP);
		if (res == 0 && !*line)
			break;
		height++;
		safe_free((void**)&line);
	}
	safe_free((void**)&line);
	close(fd);
	return (height);
}

//void	fill_matrix(int *z_line, int *color_line, char *line)
//{
//	char	**nums;
//	char	**portion;
//	int		i;

//	nums = ft_split(line, ' ');
//	i = 0;
//	while(nums[i])
//	{
//		portion = ft_split(nums[i], ',');
//		z_line[i] = ft_atoi(portion[Z_VALUE]);
//		if (portion[1])
//			color_line[i] = ft_atoi(portion[COLOR_VALUE]);
//		else
//			color_line[i] = -1;
//		free(nums[i]);
//		free(portion);
//		i++;
//	}
//	free(nums);
//}

void	fill_z_line(int *z_line, char *line)
{
	char	**nums;
	char	**portion;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while(nums[i])
	{
		portion = ft_split(nums[i], ',');
		z_line[i] = ft_atoi(portion[Z_VALUE]);
		safe_free((void**)&nums[i]);
		safe_free((void**)portion);
		i++;
	}
	safe_free((void**)nums);
}

//int get_warm_color(float ratio)
//{
//	if (ratio < 0.15)
//		return (0x009e96);
//	else if (ratio < 0.3)
//		return (0x009944);
//	else if (ratio < 0.45)
//		return (0x8fc31f);
//	else if (ratio < 0.6)
//		return (0xfff100);
//	else if (ratio < 0.75)
//		return (0xf39800);
//	else
//		return (0xe60012);
//}

//int get_cold_color(float ratio)
//{
//	if (ratio < 0.15)
//		return (0x00a0e9);
//	else if (ratio < 0.3)
//		return (0x0068b7);
//	else if (ratio < 0.45)
//		return (0x1d2088);
//	else if (ratio < 0.6)
//		return (0x920783);
//	else if (ratio < 0.75)
//		return (0xe4007f);
//	else
//		return (0xe5004f);
//}

void	fill_color_line(int *color_line, int *z_line, t_map *map, char *line)
{
	char	**nums;
	char	**portion;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while(nums[i])
	{
		portion = ft_split(nums[i], ',');
		if (portion[COLOR_VALUE])
			color_line[i] = ft_atoi(portion[COLOR_VALUE]);
		else
			color_line[i] = default_color(z_line[i], map);
		safe_free((void**)&nums[i]);
		safe_free((void**)portion);
		i++;
	}
	safe_free((void**)nums);
}

void	fill_z_matrix(t_map *map)
{
	int		fd;
	char	*line;
	int		i;
	int res;

	fd = open(map->name, O_RDONLY);
	i = 0;
	printf("%s\n", map->name);
	while((res = get_next_line(fd, &line)))
	{
		printf("res : %d\n", res);
		printf("i : %d\n", i);
		printf("line : %s\n", line);
		fill_z_line(map->z_matrix[i], line);
		free(line);
		line = NULL;
		i++;
	}
	printf("res : %d\n", res);
	printf("cccc\n");
	close(fd);
	map->z_matrix[i] = NULL;
}

void	fill_color_matrix(t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(map->name, O_RDONLY);
	i = 0;
	while(get_next_line(fd, &line))
	{
		fill_color_line(map->color_matrix[i], map->z_matrix[i], map, line);
		free(line);
		i++;
	}
	close(fd);
	map->color_matrix[i] = NULL;
}

void	get_z_range(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->z_max < map->z_matrix[y][x])
				map->z_max = map->z_matrix[y][x];
			if (map->z_min > map->z_matrix[y][x])
				map->z_min = map->z_matrix[y][x];
			x++;
		}
		y++;
	}
}

void	read_file(t_map *map)
{
	fill_z_matrix(map);
	printf("bbbb\n");
	get_z_range(map);
	fill_color_matrix(map);
}
