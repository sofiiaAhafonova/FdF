/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:10:09 by sahafono          #+#    #+#             */
/*   Updated: 2017/11/21 20:10:11 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*buf;

	len = ft_strlen(s1) + 1;
	buf = (char*)malloc(len);
	if (buf == NULL)
		return (NULL);
	ft_strncpy(buf, s1, len);
	return (buf);
}
