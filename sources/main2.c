#include "fdf.h"

int	deal_key(int key, t_fdf *data)
{
	(void)data;
	printf("%d\n", key);

	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 27)
		data->zoom -= 5;
	if (key == 41)
		data->zoom += 5;
	if (key == 43)
		data->flatten += 1;
	if (key == 47)
		data->flatten -= 1;

	mlx_clear_window(data->mlx, data->win);
	draw(data);
	return (0);
}

int main(int argc, char **argv)
{
	t_fdf *data;

	(void)argc;
	data = malloc(sizeof(t_fdf));
	data->z_max = INT_MIN;
	data->z_min = INT_MAX;
	read_file(argv[1], data);;

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "FDF");
	data->zoom = 10;
	data->flatten = 10;
	data->shift_x = 450;
	data->shift_y = 300;
	//mlx_pixel_put(data->mlx_ptr, data->win_ptr, (int)x, (int)y, 0xFFFFFF);

	//t_point start;
	//t_point end;

	//start.x = 30;
	//start.y = 30;
	//end.x = 30;
	//end.y = 10;
	//bresenham(start, end, data);
	draw(data);
	//for (int i = 0; i < data->height; i++)
	//{
	//	for (int j = 0; j < data->width; j++)
	//	{
	//		printf(" %x ", data->color_matrix[i][j]);
	//	}
	//	printf("\n");
	//}
	mlx_hook(data->win, 2, 0, deal_key, data);
	//mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx);
}
/*
left 123
right 124
up 126
down 125
*/