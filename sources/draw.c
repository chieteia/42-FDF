/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:03:10 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/10/04 22:03:10 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_point start, t_point end, t_fdf *fdf)
{
	t_set	delta;
	t_set	step;
	t_set	cur;
	int		err[2];

	delta = (t_set){abs(end.x - start.x), abs(end.y - start.y)};
	step = (t_set){2 * (start.x < end.x) - 1, 2 * (start.y < end.y) - 1};
	cur = (t_set){start.x, start.y};
	err[0] = delta.x - delta.y;
	while (cur.x != end.x || cur.y != end.y)
	{
		my_mlx_pixel_put(fdf, cur.x, cur.y, get_color(cur, start, end, delta));
		err[1] = 2 * err[0];
		if (err[1] > -delta.y)
		{
			err[0] -= delta.y;
			cur.x += step.x;
		}
		if (err[1] < delta.x)
		{
			err[0] += delta.x;
			cur.y += step.y;
		}
	}
}

void	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	setup_drawing(fdf);
	y = -1;
	while (++y < fdf->map->height)
	{
		x = -1;
		while (++x < fdf->map->width)
		{
			if (x < fdf->map->width - 1)
				bresenham(projection(new_point(x, y, fdf), fdf), \
							projection(new_point(x + 1, y, fdf), fdf), fdf);
			if (y < fdf->map->height - 1)
				bresenham(projection(new_point(x, y, fdf), fdf), \
							projection(new_point(x, y + 1, fdf), fdf), fdf);
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	draw_translation(fdf);
}
