/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:06:42 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/10/04 22:06:43 by ntoshihi         ###   ########.fr       */
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

int	ft_atoi_base(const char *str, int base)
{
	int64_t	res;
	int		index;
	int		minus;

	res = 0;
	index = 0;
	minus = 0;
	while (ft_isspace(str[index]))
		index++;
	if (base != 10 && !ft_has_prefix(&str[index], base))
		return (-1);
	if (base == 2 || base == 16)
		index += 2;
	else if (base == 8)
		index++;
	else if (base == 10 && (str[index] == '-' || str[index] == '+'))
		minus = (str[index++] == '-');
	while (ft_isdigit_base(str[index], base) >= 0)
		res = res * base + ft_isdigit_base(str[index++], base);
	if (minus)
		res *= -1;
	return ((int)res);
}
