#include "fdf.h"

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
