/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:25:39 by sahafono          #+#    #+#             */
/*   Updated: 2017/11/21 21:05:15 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	int		i;
	int		n;
	size_t	k;

	k = 0;
	i = 0;
	len = ft_strlen(dst);
	n = dstsize - len;
	while (--n > 0 && src[i])
	{
		dst[len + i] = src[i];
		++i;
	}
	while (k < len && k < dstsize)
		++k;
	dst[i + len] = '\0';
	return (k + ft_strlen(src));
}
