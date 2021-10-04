/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:02:49 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/10/04 22:02:50 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == BUTTON_MINUS || key == MOUSE_SCROLL_DOWN)
		fdf->camera->zoom -= 1;
	else if (key == BUTTON_PLUS || key == MOUSE_SCROLL_UP)
		fdf->camera->zoom += 1;
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
	draw(fdf);
}

void	shift(int key, t_fdf *fdf)
{
	if (key == ARROW_UP)
		fdf->camera->shift_y -= 50;
	else if (key == ARROW_DOWN)
		fdf->camera->shift_y += 50;
	else if (key == ARROW_LEFT)
		fdf->camera->shift_x -= 50;
	else if (key == ARROW_RIGHT)
		fdf->camera->shift_x += 50;
	draw(fdf);
}

void	sharpen(int key, t_fdf *fdf)
{
	if (key == BUTTON_LESS)
		fdf->camera->z_divisor += 0.1;
	else if (key == BUTTON_MORE)
		fdf->camera->z_divisor -= 0.1;
	if (fdf->camera->z_divisor < 0.1)
		fdf->camera->z_divisor = 0.1;
	draw(fdf);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == BUTTON_1)
		fdf->camera->alpha += 0.2;
	else if (key == BUTTON_7)
		fdf->camera->alpha -= 0.2;
	else if (key == BUTTON_2)
		fdf->camera->beta += 0.2;
	else if (key == BUTTON_8)
		fdf->camera->beta -= 0.2;
	else if (key == BUTTON_3)
		fdf->camera->gamma += 0.2;
	else if (key == BUTTON_9)
		fdf->camera->gamma -= 0.2;
	draw(fdf);
}

void	setup_projection(int key, t_fdf *fdf)
{
	if (key == BUTTON_I)
		fdf->camera->projection = ISO;
	else if (key == BUTTON_P)
		fdf->camera->projection = PARALLEL;
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	draw(fdf);
}
