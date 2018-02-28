/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:01:25 by sahafono          #+#    #+#             */
/*   Updated: 2017/11/26 16:01:26 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rec(unsigned int nb)
{
	if (nb / 10)
		ft_rec(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void		ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_rec(-n);
	}
	else
		ft_rec(n);
}
