/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:48:26 by sahafono          #+#    #+#             */
/*   Updated: 2017/11/22 18:48:28 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (s1 && s2 && (str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		str = ft_strcat(str, (char *)s1);
		str = ft_strcat(str, (char *)s2);
		return (str);
	}
	return (NULL);
}
