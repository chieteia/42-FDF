#include "fdf.h"

int	press_keys(int key, t_fdf *fdf)
{
	printf("%d\n", key);

	if (key == 126)
		fdf->camera->shift_y -= 50;
	if (key == 125)
		fdf->camera->shift_y += 50;
	if (key == 123)
		fdf->camera->shift_x -= 50;
	if (key == 124)
		fdf->camera->shift_x += 50;
	if (key == 27)
		fdf->camera->zoom -= 1;
	if (key == 41)
		fdf->camera->zoom += 1;
	if (key == 43)
		fdf->camera->z_divisor+= 0.1;
	if (key == 47)
		fdf->camera->z_divisor -= 0.1;
	if (key == 53)
		exit(0);

	mlx_clear_window(fdf->mlx, fdf->win);
	draw(fdf);
	return (0);
}

int close_window(void *param)
{
	(void)param;
	exit(0);
}

void	deal_keys(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, press_keys, fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
}