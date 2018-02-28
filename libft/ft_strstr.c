/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:26:53 by sahafono          #+#    #+#             */
/*   Updated: 2017/11/21 21:26:55 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t len;

	if (!*needle)
		return ((char*)haystack);
	len = ft_strlen(needle);
	while (*haystack)
		if (!ft_memcmp(haystack++, needle, len))
			return ((char*)haystack - 1);
	return (0);
}
