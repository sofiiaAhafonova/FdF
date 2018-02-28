/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:46:49 by sahafono          #+#    #+#             */
/*   Updated: 2017/11/15 12:46:53 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *a;
	const unsigned char *b;

	a = s1;
	b = s2;
	while (n--)
	{
		if (*a != *b)
			return (*a - *b);
		else
		{
			a++;
			b++;
		}
	}
	return (0);
}
