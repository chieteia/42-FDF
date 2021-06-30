#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "structher.h"
# include "libft.h"
# include "get_next_line.h"
# include "error_msg.h"

# define Z_VALUE 0
# define COLOR_VALUE 1

# define PURPLE 0xba55d3
# define BLUE 0x4169e1
# define GREEN 0x7fffd4
# define YELLOW 0xffd700
# define ORANGE 0xf4a460
# define RED 0xc71585
# define WHITE 0x708090

t_admin	*init_master();

void	terminate(char *s);

void	read_map(const int fd, t_admin *master, t_list **map_data);

void	free_str_array(char ***array);
char	**parsed_by_char(char *line, char c);
int		count_word(const char *s, char c);

void	read_file(t_map *map);
void	fill_matrix(int *z_line, int *color_matrix, char *line);
int		get_width(char *file_name);
int 	get_height(char *file_name);
float	get_ratio_of_abs(int num, int min, int max);
int		default_color(int z, t_map *map);

void	bresenham(t_point start, t_point end, t_fdf *data);
float	get_percent(int start, int end, int current);
void	draw(t_fdf *data);

// init_utils
t_map		*init_map(char *file_name);
t_camera	*init_camera(void);
t_fdf		*init_fdf(char *file_name);

#endif
