#include "fdf.h"

void	rotate_x(int *y, int *z, double alpha)
{
	int	previous_y;
	int	previous_z;

	previous_y = *y;
	previous_z = *z;

	*y = (int)(previous_y * cos(alpha) + previous_z * sin(alpha));
	*z = (int)(-previous_y * sin(alpha) + previous_z * cos(alpha));
}

void	rotate_y(int *x, int *z, double beta)
{
	int	previous_x;
	int	previous_z;

	previous_x = *x;
	previous_z = *z;

	*x = (int)(previous_x * cos(beta) + previous_z * sin(beta));
	*z = (int)(-previous_x * sin(beta) + previous_z * cos(beta));
}

void	rotate_z(int *y, int *x, double gamma)
{
	int	previous_y;
	int	previous_x;

	previous_y = *y;
	previous_x = *x;

	*y = (int)(previous_y * cos(gamma) + previous_x * sin(gamma));
	*x = (int)(-previous_y * sin(gamma) + previous_x * cos(gamma));
}