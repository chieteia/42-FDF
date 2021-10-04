/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:08:57 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/10/04 22:08:58 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;
	int		l;
	int		charset[300];

	if (!(s1 && set))
		return (NULL);
	i = 0;
	while (i < 300)
		charset[i++] = 0;
	while (*set)
	{
		j = (int)*set++;
		charset[j]++;
	}
	while (*s1 && charset[(int)*s1])
		s1++;
	l = ft_strlen(s1);
	while (l && charset[(int)s1[l - 1]])
		l--;
	if (!(ft_malloc((void **)&res, sizeof(char), l + 1)))
		return (NULL);
	ft_strlcpy(res, s1, l + 1);
	return (res);
}
