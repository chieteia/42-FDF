/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:05:53 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/10/04 22:05:53 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define SCREEN_WIDTH 1500
# define SCREEN_HEIGHT 1000

# define MAP_WIDTH 0
# define MAP_HEIGHT 1

# define Z_VALUE 0
# define COLOR_VALUE 1

# define ISO 0
# define PARALLEL 1

//  check_utils
void		check_current_map_width(int current_width, int *size);
int			check_end_conditions(int res, char *line);

// color_utils
int			get_rgb(int start, int end, float percent);
int			get_color(t_set cur, t_point start, t_point end, t_set delta);
int			default_color(int z, t_map *map);

// control_utils
void		zoom(int key, t_fdf *fdf);
void		shift(int key, t_fdf *fdf);
void		sharpen(int key, t_fdf *fdf);
void		rotate(int key, t_fdf *fdf);
void		setup_projection(int key, t_fdf *fdf);

// control
int			deal_keys(t_fdf *fdf);

// draw_utils
void		my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
void		draw_background(t_fdf *fdf);
void		setup_drawing(t_fdf *fdf);
void		draw_translation(t_fdf *fdf);

// draw
void		bresenham(t_point start, t_point end, t_fdf *data);
void		draw(t_fdf *data);

// init
t_fdf		*init_fdf(char *file_name);

// init_utils
void		list_to_array(t_map *map, t_list **map_data);

// math_utils
int			int_max(int a, int b);
int			int_min(int a, int b);
float		get_percent(int start, int end, int current);

// move utils
void		rotate_x(int *y, int *z, double alpha);
void		rotate_y(int *x, int *z, double beta);
void		rotate_z(int *y, int *x, double gamma);

// new_data
t_data		*new_data(char *str);

// projection
t_point		new_point(int x, int y, t_fdf *fdf);
t_point		projection(t_point point, t_fdf *fdf);

// random_utils
void		free_str_array(char ***array);
void		terminate(char *s);

// read_map
void		read_map(const int fd, int *size, t_list **map_data);

#endif
