/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:21:16 by sahafono          #+#    #+#             */
/*   Updated: 2017/11/21 21:21:17 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *start;

	start = (char *)s;
	while (*s)
		s++;
	while (s >= start)
	{
		if (*s == c)
			return ((char *)s);
		s--;
	}
	return (0);
}
