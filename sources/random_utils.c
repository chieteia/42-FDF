/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:05:08 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/10/04 22:05:09 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_str_array(char ***array)
{
	int		index;
	char	**tmp;

	index = 0;
	tmp = *array;
	while (tmp[index])
		safe_free((void **)&tmp[index++]);
	free(*array);
	*array = NULL;
}

void	terminate(char *s)
{
	ft_putstr_fd(s, 2);
	exit(0);
}
