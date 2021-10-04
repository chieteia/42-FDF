/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:04:58 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/10/04 22:04:58 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	check_map_value(char **parsed_str)
{
	if (!ft_isnumber(parsed_str[0], 10)
		|| (parsed_str[1] && !ft_isnumber(parsed_str[1], 16)))
		terminate(ERR_INCORRECT_MAP);
}

static t_data	*get_map_data(char **parsed_str)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		terminate(ERR_MALLOC);
	new->z = ft_atoi(parsed_str[0]);
	if (parsed_str[1])
		new->color = ft_atoi_base(parsed_str[1], 16);
	else
		new->color = -1;
	return (new);
}

t_data	*new_data(char *str)
{
	t_data	*new;
	char	**parsed_str;

	parsed_str = ft_split(str, ',');
	if (!parsed_str)
		terminate(ERR_MALLOC);
	check_map_value(parsed_str);
	new = get_map_data(parsed_str);
	free_str_array(&parsed_str);
	return (new);
}
