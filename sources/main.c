#include "fdf.h"

int main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc == 2)
	{
		fdf = init_fdf(argv[1]);
		draw(fdf);
		deal_keys(fdf);
		mlx_loop(fdf->mlx);
	}
	else
		terminate(ERR_USAGE);
}
