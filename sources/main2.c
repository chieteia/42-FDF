#include "fdf.h"

int	deal_key(int key, t_fdf *fdf)
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

//int print_pos(int key, int x, int y, t_fdf *param)
//{
//	(void)param;
//	(void)key;
//	printf("%d %d", x, y);
//	return (0);
//}

int main(int argc, char **argv)
{
	t_fdf *fdf;

	(void)argc;
	fdf = init_fdf(argv[1]);
	read_file(fdf->map);;

	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1920, 1080, "FDF");
	//mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)x, (int)y, 0xFFFFFF);

	//t_point start;
	//t_point end;

	//start.x = 30;
	//start.y = 30;
	//end.x = 30;
	//end.y = 10;
	//bresenham(start, end, fdf);
	draw(fdf);
	//for (int i = 0; i < fdf->height; i++)
	//{
	//	for (int j = 0; j < fdf->width; j++)
	//	{
	//		printf(" %x ", fdf->color_matrix[i][j]);
	//	}
	//	printf("\n");
	//}
	mlx_hook(fdf->win, 2, 0, deal_key, fdf);
	//mlx_hook(fdf->win, 6, (1L<<6), print_pos, fdf);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
	//mlx_key_hook(fdf->win_ptr, deal_key, fdf);
	mlx_loop(fdf->mlx);
}
/*
left 123
right 124
up 126
down 125
*/