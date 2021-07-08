#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "keys.h"
# include "color.h"
# include "structher.h"
# include "libft.h"
# include "get_next_line.h"
# include "error_message.h"
# include <math.h>

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# define MAP_WIDTH 0
# define MAP_HEIGHT 1

# define Z_VALUE 0
# define COLOR_VALUE 1

void	read_map(const int fd, int *size, t_list **map_data);

void	free_str_array(char ***array);
//char	**parsed_by_char(char *line, char c);
int		count_word(const char *s, char c);
int		default_color(int z, t_map *map);
void	terminate(char *s);

t_data	*new_data(char *str);

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
int		deal_keys(t_fdf *fdf);

// move utils
void	rotate_x(int *y, int *z, double alpha);
void	rotate_y(int *x, int *z, double beta);
void	rotate_z(int *y, int *x, double gamma);

#endif
