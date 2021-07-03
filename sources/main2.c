#include "fdf.h"

//int	deal_key(int key, t_fdf *fdf)
//{
//	printf("%d\n", key);

//	if (key == 126)
//		fdf->camera->shift_y -= 50;
//	if (key == 125)
//		fdf->camera->shift_y += 50;
//	if (key == 123)
//		fdf->camera->shift_x -= 50;
//	if (key == 124)
//		fdf->camera->shift_x += 50;
//	if (key == 27)
//		fdf->camera->zoom -= 1;
//	if (key == 41)
//		fdf->camera->zoom += 1;
//	if (key == 43)
//		fdf->camera->z_divisor+= 0.1;
//	if (key == 47)
//		fdf->camera->z_divisor -= 0.1;
//	if (key == 53)
//		exit(0);

//	mlx_clear_window(fdf->mlx, fdf->win);
//	draw(fdf);
//	return (0);
//}

int main(int argc, char **argv)
{
	t_list	*map_data;
	t_fdf	*fdf;
	//int y = 9;
	//int x = 10;

	if (argc == 2)
	{
		map_data = NULL;
		fdf = init_fdf(argv[1]);
		draw(fdf);
		deal_keys(fdf);
		mlx_loop(fdf->mlx);
		//READ_MAP debug ↓↓↓
		//while (map_data)
		//{
		//	i++;
		//	map_data = map_data->next;
		//}
		//printf("%d", i);
		//while (y--)
		//{
		//	x = 10;
		//	while (x--)
		//	{
		//		data = (t_data*)map_data->content;
		//		printf("%d ", data->z);
		//		map_data = map_data->next;
		//	}
		//	printf("\n");
		//}
	}
}
