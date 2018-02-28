/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:28:54 by sahafono          #+#    #+#             */
/*   Updated: 2017/11/22 19:28:55 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	int		len_new;
	char	*str;

	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	len_new = len + 1;
	while (*s == ' ' || *s == '\t' || *s == '\n')
	{
		len_new--;
		s++;
	}
	if (len_new < 1)
		len_new = ft_strlen(s);
	if (!(str = ft_strnew(len_new)))
		return (NULL);
	len = len_new;
	if (str)
		while (len_new--)
			*str++ = *s++;
	return (str - len);
}
