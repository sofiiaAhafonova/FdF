/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:19:02 by sahafono          #+#    #+#             */
/*   Updated: 2017/11/21 19:19:04 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dp;
	unsigned const char	*sp;

	dp = dst;
	sp = src;
	while (n--)
	{
		*dp = *sp;
		if (*sp == (unsigned char)c)
		{
			++dp;
			return ((unsigned char*)dp);
		}
		dp++;
		sp++;
	}
	return (NULL);
}
