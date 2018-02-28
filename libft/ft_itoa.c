/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 20:51:43 by sahafono          #+#    #+#             */
/*   Updated: 2017/11/25 20:51:45 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countchr(int n)
{
	size_t len;

	len = 1;
	if (n < 0)
		len++;
	while (n /= 10)
		len++;
	return (len);
}

char			*ft_itoa(int n)
{
	int		len;
	long	buf;
	char	*str;
	int		sign;

	sign = (n < 0) ? -1 : 1;
	len = ft_countchr(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	buf = (long)sign * n;
	len = (sign < 0) ? len - 1 : len;
	while (len--)
	{
		*str++ = (buf % 10) + '0';
		buf /= 10;
	}
	if (sign < 0)
		*str++ = '-';
	str = ft_strrev(str - ft_countchr(n));
	return (str);
}
