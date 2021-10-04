/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:07:10 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/10/04 22:07:12 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	ft_has_prefix(const char *str, int base)
{
	if (base == 2 || base == 8 || base == 16)
	{
		if (*str++ != '0')
			return (FALSE);
		if (base == 2 && (*str == 'b' || *str == 'B'))
			return (TRUE);
		if (base == 8)
			return (TRUE);
		if (base == 16 && (*str == 'x' || *str == 'X'))
			return (TRUE);
	}
	return (FALSE);
}

int	ft_isnumber(char *str, int base)
{
	int	index;
	int	digits;

	index = 0;
	digits = 0;
	while (ft_isspace(str[index]))
		index++;
	if (base != 10 && !ft_has_prefix(&str[index], base))
		return (FALSE);
	if (base == 2 || base == 16)
		index += 2;
	else if (base == 8)
		index++;
	else if (base == 10 && (str[index] == '-' || str[index] == '+'))
		index++;
	while (ft_isdigit_base(str[index], base) >= 0)
	{
		index++;
		digits++;
	}
	return (!str[index] && digits);
}
