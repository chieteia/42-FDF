/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:07:57 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/10/04 22:07:58 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*res;
	const char	*sr;

	res = (char *)dest;
	sr = (const char *)src;
	if (!(dest || src))
		return (NULL);
	while (n--)
	{
		*res = *sr;
		res++;
		sr++;
	}
	return (dest);
}
