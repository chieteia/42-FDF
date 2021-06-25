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

typedef struct s_map
{
	int		width;
	int		height;
}				t_map;

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
	t_map	*map;
}				t_admin;

#endif
