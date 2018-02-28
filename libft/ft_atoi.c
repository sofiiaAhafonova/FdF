/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:37:18 by sahafono          #+#    #+#             */
/*   Updated: 2017/11/08 17:45:14 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long int	result;
	int					i;
	int					sign;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n' || str[i] == '\r'
	|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		if (result >= 9223372036854775807 && sign == 1)
			return (-1);
		else if (result > 9223372036854775807 && sign == -1)
			return (0);
		i++;
	}
	return ((int)(result * sign));
}
