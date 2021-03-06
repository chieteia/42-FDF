/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:04:50 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/10/04 22:04:50 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	int_max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	int_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

float	get_percent(int start, int end, int current)
{
	float	position;
	float	distance;

	position = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (position / distance);
}
