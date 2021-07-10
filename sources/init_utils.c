#include "fdf.h"

static void	malloc_array(t_map *map)
{
	int	i;

	i = 0;
	map->z_matrix = malloc(sizeof(int *) * (map->height));
	if (!map->z_matrix)
		terminate(ERR_MALLOC);
	map->color_matrix = malloc(sizeof(int *) * (map->height));
	if (!map->color_matrix)
		terminate(ERR_MALLOC);
	while (i < map->height)
	{
		map->z_matrix[i] = malloc(sizeof(int) * map->width);
		if (!map->z_matrix[i])
			terminate(ERR_MALLOC);
		map->color_matrix[i] = malloc(sizeof(int) * map->width);
		if (!map->color_matrix[i])
			terminate(ERR_MALLOC);
		i++;
	}
}

static void	copy_to_array(t_map *map, t_list *map_data)
{
	int		x;
	int		y;
	t_data	*tmp;

	map->z_max = INT_MIN;
	map->z_min = INT_MAX;
	y = map->height;
	while (0 <= --y)
	{
		x = map->width;
		while (0 <= --x)
		{
			tmp = (t_data *)(map_data->content);
			map->z_matrix[y][x] = tmp->z;
			map->color_matrix[y][x] = tmp->color;
			map->z_max = int_max(map->z_max, tmp->z);
			map->z_min = int_min(map->z_min, tmp->z);
			map_data = map_data->next;
		}
	}
}

void	list_to_array(t_map *map, t_list **map_data)
{
	malloc_array(map);
	copy_to_array(map, *map_data);
	ft_lstclear(map_data, free);
}
