#include "fdf.h"

t_admin	*init_master()
{
	t_admin	*master;
	t_map	*map;

	if (!ft_malloc((void **)&master, sizeof(t_admin), 1))
		terminate(ERR_INIT);
	if (!ft_malloc((void**)&map, sizeof(t_map), 1))
		terminate(ERR_INIT);
	map->height = -1;
	map->width = -1;
	master->map = map;
	return (master);
}
