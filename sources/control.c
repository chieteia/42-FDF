#include "fdf.h"

static int	close_window(void *param)
{
	(void)param;
	exit(0);
}

static int	press_key(int key, t_fdf *fdf)
{
	if (key == ARROW_UP || key == ARROW_DOWN
		|| key == ARROW_LEFT || key == ARROW_RIGHT)
		shift(key, fdf);
	if (key == BUTTON_MINUS || key == BUTTON_PLUS)
		zoom(key, fdf);
	if (key == BUTTON_LESS || key == BUTTON_MORE)
		sharpen(key, fdf);
	if (key == BUTTON_1 || key == BUTTON_7
		|| key == BUTTON_2 || key == BUTTON_8
		|| key == BUTTON_3 || key == BUTTON_9)
		rotate(key, fdf);
	if (key == BUTTON_I || key == BUTTON_P)
		setup_projection(key, fdf);
	if (key == BUTTON_ESC)
		close_window(NULL);
	return (0);
}

static int	mouse_press(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, fdf);
	return (0);
}

int	deal_keys(t_fdf *fdf)
{
	printf("%s", "aaa");
	mlx_hook(fdf->win, 2, 0, press_key, fdf);
	mlx_hook(fdf->win, 17, 0, close_window, NULL);
	mlx_hook(fdf->win, 4, 0, mouse_press, fdf);
	return (0);
}
