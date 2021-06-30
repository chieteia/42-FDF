#ifndef STRUCTHER_H
# define STRUCTHER_H

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct s_data
{
	int				z;
	int				color;
}				t_data;

typedef struct s_admin
{
	//void	*mlx;
	//void	*mlx_win;
	//void	*img;
	//char	*addr;
	//int		bits_per_pixel;
	//int		line_length;
	//int		endian;
	//int		*ary_color;
	//int		*ary_z;
	int		width;
	int		height;
	int		**z_matrix;
}				t_admin;

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

//typedef struct s_data
//{
//	void	*img;
//	char	*addr;
//	int		bits_per_pixel;
//	int		line_length;
//	int		endian;
//}				t_data;

typedef struct s_camera
{
	int		zoom;
	float	z_divisor;
	int		shift_x;
	int		shift_y;
	float	alpha;
	float	beta;
	float	gamma;
}				t_camera;



typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	t_camera	*camera;
	t_map		*map;
}				t_fdf;

#endif
