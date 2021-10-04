/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:02:42 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/10/04 22:02:43 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_rgb(int start, int end, float percent)
{
	return ((end - start) * percent + start);
}

int	get_color(t_set cur, t_point start, t_point end, t_set delta)
{
	int		red;
	int		green;
	int		blue;
	float	percentage;

	if (delta.x > delta.y)
		percentage = get_percent(start.x, end.x, cur.x);
	else
		percentage = get_percent(start.y, end.y, cur.y);
	red = get_rgb((start.color >> 16) & 0xFF, \
				(end.color >> 16) & 0xFF, \
				percentage);
	green = get_rgb((start.color >> 8) & 0xFF, \
					(end.color >> 8) & 0xFF, \
					percentage);
	blue = get_rgb(start.color & 0xFF, \
				end.color & 0xFF, \
				percentage);
	return ((red << 16) | (green << 8) | blue);
}

int	default_color(int z, t_map *map)
{
	float	percent;

	percent = get_percent(map->z_min, map->z_max, z);
	if (percent < 0.15)
		return (PURPLE);
	else if (percent < 0.25)
		return (RIGHT_PURPLE);
	else if (percent < 0.35)
		return (BLUE);
	else if (percent < 0.5)
		return (RIGHT_BLUE);
	else if (percent < 0.7)
		return (GREEN);
	else if (percent < 0.75)
		return (YELLOW);
	else if (percent < 0.8)
		return (ORANGE);
	else if (percent < 0.9)
		return (PINK);
	else
		return (RIGHT_RED);
}
