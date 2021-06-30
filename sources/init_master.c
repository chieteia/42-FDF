#include "fdf.h"

t_admin	*init_master()
{
	t_admin	*master;

	if (!ft_malloc((void **)&master, sizeof(t_admin), 1))
		terminate(ERR_INIT);
	return (master);
}
