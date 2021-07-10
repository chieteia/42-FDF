#include "fdf.h"

static t_map	*init_map(char *file_name)
{
	t_map	*map;
	t_list	*map_data;
	int		fd;
	int		*size;

	map_data = NULL;
	size = (int []){0, 0};
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

static t_camera	*init_camera(t_map *map)
{
	t_camera	 *camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		terminate(ERR_MALLOC);
	camera->zoom = int_min(SCREEN_WIDTH / map->width / 2, \
						SCREEN_HEIGHT / map->height / 2);
	camera->z_divisor = 1;
	camera->shift_x = 480;
	camera->shift_y = 270;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->projection = ISO;
	return (camera);
}

t_fdf	*init_fdf(char *file_name)
{
	t_fdf	*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		terminate(ERR_MALLOC);
	fdf->map = init_map(file_name);
	fdf->camera = init_camera(fdf->map);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		terminate(ERR_MLX_INIT);
	fdf->win = mlx_new_window(fdf->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "FDF");
	if (!fdf->win)
		terminate(ERR_NEW_WIN);
	fdf->img = mlx_new_image(fdf->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!fdf->img)
		terminate(ERR_NEW_IMG);
	fdf->addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel), \
									&(fdf->line_length), &(fdf->endian));
	return (fdf);
}
