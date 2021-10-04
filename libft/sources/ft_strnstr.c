/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:08:48 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/10/04 22:08:49 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;

	if (!*needle)
		return ((char *)haystack);
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	i = 0;
	while (haystack[i] && i + (int)ft_strlen(needle) <= (int)len)
	{
		if (!ft_strncmp(haystack + i, needle, ft_strlen(needle)))
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
