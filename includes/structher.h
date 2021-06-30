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
	int		width;
	int		height;
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

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		**color_matrix;
	int		z_min;
	int		z_max;

	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		zoom;
	int		color;
	int		flatten;
	int		shift_x;
	int		shift_y;
}				t_fdf;

#endif
