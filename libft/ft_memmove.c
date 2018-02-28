/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:42:07 by sahafono          #+#    #+#             */
/*   Updated: 2017/11/21 19:42:08 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dp;
	const char	*sp;

	dp = dst;
	sp = src;
	if (sp > dp)
		while (len--)
			*dp++ = *sp++;
	else
	{
		dp += len;
		sp += len;
		while (len--)
			*--dp = *--sp;
	}
	return (dst);
}
