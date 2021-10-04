/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:02:24 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/10/04 22:02:27 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_current_map_width(int current_width, int *size)
{
	if (size[MAP_HEIGHT] == 0)
		size[MAP_WIDTH] = current_width;
	else if (size[MAP_WIDTH] > current_width)
		terminate(ERR_INCORRECT_MAP);
}

int	check_end_conditions(int res, char *line)
{
	if (res < 0)
		terminate(ERR_READ_MAP);
	if (res == 0 && !*line)
		return (0);
	else
		return (1);
}
