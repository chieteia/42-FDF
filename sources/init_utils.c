#include "fdf.h"

//bool	check_map(char *file_name, int width, int height)
//{
//	int		fd;
//	int		res;
//	char	*line;

//	if (height == 0)
//		terminate(ERR_EMPTY_MAP);
//	fd = open(file_name, O_RDONLY);
//	while (1)
//	{
//		res = get_next_line(fd, file_name);
//		if (res < 0)
//			terminate(ERR_READ_MAP);
//		if (width != count_word(line, ' '))
//			terminate(ERR_MAP_COMPOSITION);
//		safe_free((void **)&line);
//	}
//	close(fd);
//}

t_map	*init_map(char *file_name)
{
	t_map		*map;
	t_list		*map_data;
	int			fd;
	int			i;
	static int	size[2];

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		terminate(ERR_OPEN_FILE);
	map_data = NULL;
	read_map(fd, size, &map_data);
	map = malloc(sizeof(t_map));
	map->name = file_name;
	map->width = size[MAP_WIDTH];
	map->height = size[MAP_HEIGHT];
	printf("height : %d width : %d\n", map->height, map->width);
	exit(0);
	check_map_form(map);
	map->z_matrix = malloc(sizeof(int*) * (map->height + 1));
	map->color_matrix = malloc(sizeof(int*) * (map->height + 1));
	i = 0;
	while(i <= map->height)
	{
		map->z_matrix[i] = malloc(sizeof(int) * map->width);
		map->color_matrix[i] = malloc(sizeof(int) * map->width);
		i++;
	}
	map->z_min = INT_MAX;
	map->z_max = INT_MIN;
	return (map);
}

t_camera	*init_camera(void)
{
	t_camera	 *camera;

	camera = malloc(sizeof(camera));
	camera->zoom = 10;
	camera->z_divisor = 1;
	camera->shift_x = 256;
	camera->shift_y = 160;
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
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "FDF");
	fdf->img = mlx_new_image(fdf->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	fdf->addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
									&(fdf->line_length), &(fdf->endian));
	fdf->camera = init_camera();
	return (fdf);
}