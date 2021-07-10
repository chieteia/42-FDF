#ifndef STRUCTHER_H
# define STRUCTHER_H

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct s_set
{
	int	x;
	int	y;
}				t_set;

typedef struct s_data
{
	int				z;
	int				color;
}				t_data;

typedef struct s_map
{
	char	*name;
	int		height;
	int		width;
	int		**z_matrix;
	int		**color_matrix;
	int		z_min;
	int		z_max;
}				t_map;
typedef struct s_camera
{
	int		zoom;
	float	z_divisor;
	int		shift_x;
	int		shift_y;
	double	alpha;
	double	beta;
	double	gamma;
	int		projection;
}				t_camera;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;

	t_camera	*camera;
	t_map		*map;
}				t_fdf;

#endif
