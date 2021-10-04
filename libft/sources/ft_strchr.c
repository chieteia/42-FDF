/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:08:21 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/10/04 22:08:21 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*res;

	res = NULL;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
		{
			res = (char *)&(*s);
			break ;
		}
		s++;
	}
	return (res);
}
