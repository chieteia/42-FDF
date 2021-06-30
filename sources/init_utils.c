#include "fdf.h"

t_map	*init_map(char *file_name)
{
	t_map	*map;
	int		i;

	map = malloc(sizeof(t_map));
	map->name = file_name;
	map->height = get_height(file_name);
	map->width = get_width(file_name);
	map->z_matrix = malloc(sizeof(int*) * (map->height + 1));
	map->color_matrix = malloc(sizeof(int*) * (map->height + 1));
	i = -1;
	while(++i <= map->height)
	{
		map->z_matrix[i] = malloc(sizeof(int) * map->width);
		map->color_matrix[i] = malloc(sizeof(int) * map->width);
	}
	map->z_min = INT_MAX;
	map->z_max = INT_MIN;
	return (map);
}

t_camera	*init_camera(void)
{
	t_camera	 *camera;

	camera = malloc(sizeof(camera));
	camera->zoom = 1;
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
	fdf->camera = init_camera();
	return (fdf);
}