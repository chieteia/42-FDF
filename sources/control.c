#include "fdf.h"

int	press_key(int key, t_fdf *fdf)
{
	//printf("%d", key);

	if (key == ARROW_UP)
		fdf->camera->shift_y -= 50;
	if (key == ARROW_DOWN)
		fdf->camera->shift_y += 50;
	if (key == ARROW_LEFT)
		fdf->camera->shift_x -= 50;
	if (key == ARROW_RIGHT)
		fdf->camera->shift_x += 50;
	if (key == BUTTON_MINUS)
		fdf->camera->zoom -= 1;
	if (key == BUTTON_PLUS)
		fdf->camera->zoom += 1;
	if (key == BUTTON_LESS)
		fdf->camera->z_divisor+= 0.1;
	if (key == BUTTON_MORE)
		fdf->camera->z_divisor -= 0.1;
	if (key == 18)
	{
		ft_putstr_fd("ok", 2);
		fdf->camera->alpha += 0.05;
	}
	if (key == 19)
		fdf->camera->beta += 0.05;
	if (key == 20)
		fdf->camera->gamma += 0.05;
	if (key == BUTTON_ESC)
		exit(0);
	draw(fdf);
	return (0);
}

int close_window(void *param)
{
	(void)param;
	exit(0);
}

int	deal_keys(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, press_key, fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
	return (0);
}