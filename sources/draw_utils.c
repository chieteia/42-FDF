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

void	setup_drawing(t_fdf *fdf)
{
	t_point	origin;

	draw_background(fdf);
	origin = projection(new_point(0, 0, fdf), fdf);
	my_mlx_pixel_put(fdf, origin.x, origin.y, origin.color);
}

void	draw_translation(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 60, 40, ORANGE, "42 FDF");
	mlx_string_put(fdf->mlx, fdf->win, 25, 80, WHITE, "Zoom : + or -");
	mlx_string_put(fdf->mlx, fdf->win, 25, 110, WHITE, "Move : Arrows");
	mlx_string_put(fdf->mlx, fdf->win, 25, 140, WHITE, "Sharpen : < or >");
	mlx_string_put(fdf->mlx, fdf->win, 25, 170, BLUE, "Rotate_X : 1 or 7");
	mlx_string_put(fdf->mlx, fdf->win, 25, 200, RED, "Rotate_Y : 2 or 8");
	mlx_string_put(fdf->mlx, fdf->win, 25, 230, GREEN, "Rotate_Z : 3 or 9");
}
