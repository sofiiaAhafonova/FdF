/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:01:32 by sahafono          #+#    #+#             */
/*   Updated: 2017/11/26 16:01:33 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rec_fd(unsigned int nb, int fd)
{
	if (nb / 10)
		ft_rec_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_rec_fd(-n, fd);
	}
	else
		ft_rec_fd(n, fd);
}
