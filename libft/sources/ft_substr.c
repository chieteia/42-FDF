/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:09:00 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/10/04 22:09:01 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	l;
	char	*res;

	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	if (start >= l)
		return (ft_strdup(""));
	if (l - start < len)
		size = l - start;
	else
		size = len;
	if (!(ft_malloc((void **)&res, sizeof(char), size + 1)))
		return (NULL);
	ft_strlcpy(res, s + start, size + 1);
	return (res);
}
