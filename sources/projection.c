#include "fdf.h"

static void	isometric(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - z;
}

t_point	new_point(int x, int y, t_fdf *fdf)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = fdf->map->z_matrix[y][x];
	if (fdf->map->color_matrix[y][x] == -1)
		point.color = default_color(point.z, fdf->map);
	else
		point.color = fdf->map->color_matrix[y][x];
	return (point);
}

t_point	projection(t_point point, t_fdf *fdf)
{
	point.x *= fdf->camera->zoom;
	point.y *= fdf->camera->zoom;
	point.z *= fdf->camera->zoom / fdf->camera->z_divisor;
	rotate_x(&point.y, &point.z, fdf->camera->alpha);
	rotate_y(&point.x, &point.z, fdf->camera->beta);
	rotate_z(&point.y, &point.x, fdf->camera->gamma);
	if (fdf->camera->projection == ISO)
		isometric(&point.x, &point.y, point.z);
	point.x += fdf->camera->shift_x;
	point.y += fdf->camera->shift_y;
	return (point);
}
