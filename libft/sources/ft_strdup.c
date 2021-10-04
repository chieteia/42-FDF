/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoshihi <ntoshihi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:08:25 by ntoshihi          #+#    #+#             */
/*   Updated: 2021/10/04 22:08:26 by ntoshihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;

	if (!(ft_malloc((void **)&res, sizeof(char), ft_strlen(s1) + 1)))
		return (NULL);
	ft_strlcpy(res, s1, ft_strlen(s1) + 1);
	return (res);
}
