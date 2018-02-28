/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 17:31:51 by sahafono          #+#    #+#             */
/*   Updated: 2017/11/25 17:31:53 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t begin;
	size_t end;

	if (str)
	{
		begin = 0;
		end = ft_strlen(str) - 1;
		while (begin < end)
		{
			ft_swap(str + begin, str + end);
			begin++;
			end--;
		}
		str[ft_strlen(str)] = '\0';
	}
	return (str);
}
