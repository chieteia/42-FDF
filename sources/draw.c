#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	int	i;

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		i = (y * fdf->line_length) + x * (fdf->bits_per_pixel / 8);
		fdf->addr[i] = color;
		fdf->addr[++i] = color >> 8;
		fdf->addr[++i] = color >> 16;
	}
}

float	get_percent(int start, int end, int current)
{
	float	position;
	float	distance;

	position = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (position / distance);
}

int	get_rgb(int start, int end, float percent)
{
	return ((end - start) * percent + start);
}

int	get_color(t_point current, t_point start, t_point end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	float	percentage;

	if (delta.x > delta.y)
		percentage = get_percent(start.x, end.x, current.x);
	else
		percentage = get_percent(start.y, end.y, current.y);
	red = get_rgb((start.color >> 16) & 0xFF, \
				(end.color >> 16) & 0xFF, \
				percentage);
	green = get_rgb((start.color >> 8) & 0xFF, \
					(end.color >> 8) & 0xFF, \
					percentage);
	blue = get_rgb(start.color & 0xFF, \
				end.color & 0xFF, \
				percentage);
	return ((red << 16) | (green << 8) | blue);
}

void	isometric(int *x, int *y, int z)
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
	isometric(&point.x, &point.y, point.z);
	point.x += fdf->camera->shift_x;
	point.y += fdf->camera->shift_y;
	return (point);
}

void	bresenham(t_point start, t_point end, t_fdf *fdf)
{
	t_point	delta;
	t_point	step;
	t_point	cur;
	int		err[2];

	delta = (t_point){abs(end.x - start.x), abs(end.y - start.y), 0, 0};
	step = (t_point){2 * (start.x < end.x) - 1, 2 * (start.y < end.y) - 1, 0, 0};
	cur = (t_point){start.x, start.y, 0, 0};
	err[0] = delta.x - delta.y;
	while (cur.x != end.x || cur.y != end.y)
	{
		my_mlx_pixel_put(fdf, cur.x, cur.y, get_color(cur, start, end, delta));
		err[1] = 2 * err[0];
		if (err[1] > -delta.y)
		{
			err[0] -= delta.y;
			cur.x += step.x;
		}
		if (err[1] < delta.x)
		{
			err[0] += delta.x;
			cur.y += step.y;
		}
	}
}

void	draw_background(t_fdf *fdf)
{
	int	i;
	int	*image_addr;

	image_addr = (int *)(fdf->addr);
	i = 0;
	while (i < SCREEN_HEIGHT * SCREEN_WIDTH)
	{
		image_addr[i] = BLACK;
		i++;
	}
}

void	draw_translattion(t_fdf *fdf)
{
	int	x;
	int	y;

	x = 25;
	y = 20;
	mlx_string_put(fdf->mlx, fdf->win, 60, y += 20, ORANGE, "42 FDF");
	mlx_string_put(fdf->mlx, fdf->win, x, y += 40, WHITE, "Zoom : + or -");
	mlx_string_put(fdf->mlx, fdf->win, x, y += 30, WHITE, "Move : Arrows");
	mlx_string_put(fdf->mlx, fdf->win, x, y += 30, WHITE, "Sharpen : < or >");
	mlx_string_put(fdf->mlx, fdf->win, x, y += 30, BLUE, "Rotate_X : 1 or 7");
	mlx_string_put(fdf->mlx, fdf->win, x, y += 30, RED, "Rotate_Y : 2 or 8");
	mlx_string_put(fdf->mlx, fdf->win, x, y += 30, GREEN, "Rotate_Z : 3 or 9");
}

void	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	draw_background(fdf);
	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x < fdf->map->width - 1)
				bresenham(projection(new_point(x, y, fdf), fdf), \
							projection(new_point(x + 1, y, fdf), fdf), fdf);
			if (y < fdf->map->height - 1)
				bresenham(projection(new_point(x, y, fdf), fdf), \
							projection(new_point(x, y + 1, fdf), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	draw_translattion(fdf);
}
