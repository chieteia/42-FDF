#include "fdf.h"

int main(int argc, char **argv)
{
	int		fd;
	t_list	*map_data;
	t_data	*data;
	t_admin	*master;
	//int y = 9;
	//int x = 10;

	map_data = NULL;
	data = NULL;
	master = init_master();
	if (argc == 2)
	{
		if (!((fd = open(argv[1], O_RDONLY)) >= 0))
			terminate(ERR_OPEN_FILE);
		read_map(fd, master, &map_data);

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