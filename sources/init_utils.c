#include "fdf.h"

void	malloc_array(t_map *map)
{
	int	i;

	i = 0;
	map->z_matrix = malloc(sizeof(int*) * (map->height));
	if (!map->z_matrix)
		terminate(ERR_MALLOC);
	map->color_matrix = malloc(sizeof(int*) * (map->height));
	if (!map->color_matrix)
		terminate(ERR_MALLOC);
	while(i < map->height)
	{
		map->z_matrix[i] = malloc(sizeof(int) * map->width);
		if (!map->z_matrix[i])
			terminate(ERR_MALLOC);
		map->color_matrix[i] = malloc(sizeof(int) * map->width);
		if (!map->color_matrix[i])
			terminate(ERR_MALLOC);
		i++;
	}
}

void	copy_to_array(t_map *map, t_list *map_data)
{
	int		x;
	int		y;
	t_data	*tmp;

	map->z_max = INT_MIN;
	map->z_min = INT_MAX;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			tmp = (t_data*)(map_data->content);
			map->z_matrix[y][x] = tmp->z;
			map->color_matrix[y][x] = tmp->color;
			map->z_max = int_max(map->z_max, tmp->z);
			map->z_min = int_min(map->z_min, tmp->z);
			map_data = map_data->next;
			x++;
		}
		y++;
	}
}

void	list_to_array(t_map *map, t_list **map_data)
{
	malloc_array(map);
	copy_to_array(map, *map_data);
	ft_lstclear(map_data, free);
}

t_map	*init_map(char *file_name)
{
	t_map	*map;
	t_list	*map_data;
	int		fd;
	int		size[2];

	map_data = NULL;
	ft_bzero(size, sizeof(int) * 2);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		terminate(ERR_OPEN_FILE);
	read_map(fd, size, &map_data);
	close(fd);
	map = malloc(sizeof(t_map));
	if (!map)
		terminate(ERR_MALLOC);
	map->name = file_name;
	map->width = size[MAP_WIDTH];
	map->height = size[MAP_HEIGHT];
	list_to_array(map, &map_data);
	return (map);
}

t_camera	*init_camera(t_map *map)
{
	t_camera	 *camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		terminate(ERR_MALLOC);
	camera->zoom = int_min(SCREEN_WIDTH / map->width / 2,
						SCREEN_HEIGHT / map->height / 2);
	camera->z_divisor = 1;
	camera->shift_x = 480;
	camera->shift_y = 270;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	return (camera);
}

t_fdf	*init_fdf(char *file_name)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		terminate(ERR_MALLOC);
	fdf->map = init_map(file_name);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		terminate(ERR_MLX_INIT);
	fdf->win = mlx_new_window(fdf->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "FDF");
	if (!fdf->win)
		terminate(ERR_NEW_WIN);
	fdf->img = mlx_new_image(fdf->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!fdf->img)
		terminate(ERR_NEW_IMG);
	fdf->addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
									&(fdf->line_length), &(fdf->endian));
	fdf->camera = init_camera(fdf->map);
	return (fdf);
}