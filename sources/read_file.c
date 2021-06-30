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

int get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY);
	height = 0;
	while (get_next_line(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file_name, O_RDONLY);
	get_next_line(fd, &line);
	width = count_word(line, ' ');
	free(line);
	close(fd);
	return (width);
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
		free(nums[i]);
		free(portion);
		i++;
	}
	free(nums);
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
		free(nums[i]);
		free(portion);
		i++;
	}
	free(nums);
}

void	fill_z_matrix(t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(map->name, O_RDONLY);
	i = 0;
	while(get_next_line(fd, &line))
	{
		fill_z_line(map->z_matrix[i], line);
		free(line);
		i++;
	}
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
	get_z_range(map);
	fill_color_matrix(map);
}
