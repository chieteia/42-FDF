#include "fdf.h"
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : b)
#define ABS(a) ((a) < 0 ? -(a) : (a)

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->addr + (y * fdf->line_length + x * (fdf->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

float get_percent(int start, int end, int current)
{
	float position;
	float distance;

	position = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (position / distance);
}

int get_rgb(int start, int end, float percent)
{
	return ((int)(end - start) * percent + start);
}

int get_color(t_point current, t_point start, t_point end, t_point delta)
{
	int red;
	int green;
	int blue;
	float percentage;

	if (delta.x > delta.y)
		percentage = get_percent(start.x, end.x, current.x);
	else
		percentage = get_percent(start.y, end.y, current.y);
	red = get_rgb((start.color >> 16) & 0xFF,
				(end.color >> 16) & 0xFF,
				percentage);
	green = get_rgb((start.color >> 8) & 0xFF,
					(end.color >> 8) & 0xFF,
					percentage);
	blue = get_rgb(start.color & 0xFF,
				end.color & 0xFF,
				percentage);
	return ((red << 16) | (green << 8) | blue);
}

void isometric(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = (previous_x + previous_y) * sin(0.523599) - z;
}

t_point new_point(int x, int y, t_fdf *fdf)
{
	t_point point;

	point.x = x;
	point.y = y;
	point.z = fdf->map->z_matrix[y][x];
	if (fdf->map->color_matrix[y][x] == -1)
		point.color = default_color(point.z, fdf->map);
	else
		point.color = fdf->map->color_matrix[y][x];
	return (point);
}

void bresenham(t_point start, t_point end, t_fdf *fdf)
{
	//float	x_step;
	//float	y_step;
	//float	max;
	//t_point	current;
	////zoom
	start.x *= fdf->camera->zoom;
	start.y *= fdf->camera->zoom;
	end.x *= fdf->camera->zoom;
	end.y *= fdf->camera->zoom;
	////flatten
	start.z *= fdf->camera->zoom / fdf->camera->z_divisor;
	end.z *= fdf->camera->zoom / fdf->camera->z_divisor;
	//color
	//fdf->color = (z || z1) ? (0xffa500) : (0xffffff);
	//3D
	isometric(&start.x, &start.y, start.z);
	isometric(&end.x, &end.y, end.z);
	//Shift
	start.x += fdf->camera->shift_x;
	start.y += fdf->camera->shift_y;
	end.x += fdf->camera->shift_x;
	end.y += fdf->camera->shift_y;

	//x_step = start.x - end.x;
	//y_step = start.y - end.y;

	//max = MAX(ABS(x_step), ABS(y_step));
	//x_step /= max;
	//y_step /= max;
	//current.x = start.x;
	//current.y = start.y;
	//while((int)(current.x - end.x) || (int)(current.y - end.y))
	//{
	//	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, current.x, current.y, 0xffffff);
	//	current.x += x_step;
	//	current.y += y_step;
	//}
	t_point delta;
	t_point step;
	t_point current;
	int err[2];

	delta.x = abs(end.x - start.x);
	step.x = 2 * (start.x < end.x) - 1;
	delta.y = abs(end.y - start.y);
	step.y = 2 * (start.y < end.y) - 1;
	current.x = start.x;
	current.y = start.y;
	err[0] = delta.x - delta.y;
	while (current.x == end.x && current.y == end.y)
	{
		//ft_putchar_fd('(', 2);
		//ft_putnbr_fd(current.x, 2);
		//ft_putchar_fd(' ', 2);
		//ft_putnbr_fd(current.y, 2);
		//ft_putchar_fd(')', 2);
		//ft_putchar_fd('\n', 2);
		//mlx_pixel_put(fdf->mlx, fdf->win, current.x, current.y, get_color(current, start, end, delta));
		my_mlx_pixel_put(fdf, current.x, current.y, get_color(current, start, end, delta));
		//if (current.x == end.x && current.y == end.y)
		//	break;
		err[1] = 2 * err[0];
		if (err[1] > -delta.y)
		{
			err[0] -= delta.y;
			current.x += step.x;
		}
		if (err[1] < delta.x)
		{
			err[0] += delta.x;
			current.y += step.y;
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}

//int	gradient(int x, int y, int x_dist, int y_dist, t_fdf *fdf)
//{
//	int	red;
//	int	green;
//	int	blue;

//	red =
//}

void draw(t_fdf *fdf)
{
	int x;
	int y;

	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x < fdf->map->width - 1)
				bresenham(new_point(x, y, fdf), new_point(x + 1, y, fdf), fdf);
			if (y < fdf->map->height - 1)
				bresenham(new_point(x, y, fdf), new_point(x, y + 1, fdf), fdf);
			x++;
		}
		y++;
	}
}
