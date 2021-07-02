#include "fdf.h"

void	malloc_array(t_map *map)
{
	int	i;

	i = 0;
	map->z_matrix = malloc(sizeof(int*) * (map->height + 1));
	if (!map->z_matrix)
		terminate(ERR_MALLOC);
	map->color_matrix = malloc(sizeof(int*) * (map->height + 1));
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

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			tmp = (t_data*)(map_data->content);
			map->z_matrix[y][x] = tmp->z;
			map->color_matrix[y][x] = tmp->color;
			map_data = map_data->next;
		}
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
	t_map		*map;
	t_list		*map_data;
	int			fd;
	static int	size[2];

	map_data = NULL;
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
	map->z_min = INT_MAX;
	map->z_max = INT_MIN;
	list_to_array(map, &map_data);
	return (map);
}

t_camera	*init_camera(void)
{
	t_camera	 *camera;

	camera = malloc(sizeof(camera));
	camera->zoom = 10;
	camera->z_divisor = 1;
	camera->shift_x = 0;
	camera->shift_y = 0;
	camera->alpha = 0;
	camera->beta = 0;;
	camera->gamma = 0;
	return (camera);
}

t_fdf	*init_fdf(char *file_name)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	fdf->map = init_map(file_name);
	printf("height : %d width : %d\n", fdf->map->height, fdf->map->width);
	for (int i = 0; i < fdf->map->height; i++)
	{
		for (int j = 0; j < fdf->map->width; j++)
		{
			printf("%3d", fdf->map->z_matrix[i][j]);
		}
		printf("\n");
	}
	exit(0);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "FDF");
	fdf->img = mlx_new_image(fdf->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
									&(fdf->line_length), &(fdf->endian));
	fdf->camera = init_camera();
	return (fdf);
}