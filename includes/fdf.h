#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "keys.h"
# include "structher.h"
# include "libft.h"
# include "get_next_line.h"
# include "error_message.h"
# include <math.h>

# define MAP_WIDTH 0
# define MAP_HEIGHT 1

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define Z_VALUE 0
# define COLOR_VALUE 1

# define PURPLE 0xba55d3
# define BLUE 0x4169e1
# define GREEN 0x7fffd4
# define YELLOW 0xffd700
# define ORANGE 0xf4a460
# define RED 0xc71585
# define WHITE 0xffffff
# define BLACK 0x000000

void	terminate(char *s);

void	read_map(const int fd, int *size, t_list **map_data);

void	free_str_array(char ***array);
char	**parsed_by_char(char *line, char c);
int		count_word(const char *s, char c);
int		default_color(int z, t_map *map);

t_data	*new_data(char *str);
void	read_file(t_map *map);
void	check_map_form(t_map *map);
void	fill_matrix(int *z_line, int *color_matrix, char *line);
int		get_width(char *file_name);
int 	get_height(char *file_name);
float	get_ratio_of_abs(int num, int min, int max);
int		default_color(int z, t_map *map);

void	bresenham(t_point start, t_point end, t_fdf *data);
float	get_percent(int start, int end, int current);
void	draw(t_fdf *data);

// math_utils
int		int_max(int a, int b);
int		int_min(int a, int b);

// init_utils
t_map		*init_map(char *file_name);
t_camera	*init_camera(t_map *map);
t_fdf		*init_fdf(char *file_name);

// control
int	deal_keys(t_fdf *fdf);

// move utils
void	rotate_x(int *y, int *z, double alpha);
void	rotate_y(int *x, int *z, double beta);
void	rotate_z(int *y, int *x, double gamma);

#endif
