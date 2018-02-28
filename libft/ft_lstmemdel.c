/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmemdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 12:42:18 by sahafono          #+#    #+#             */
/*   Updated: 2017/12/26 11:59:25 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmemdel(void *node, size_t size)
{
	t_list *ap;

	ap = (t_list*)node;
	if (ap)
	{
		if (size)
			ft_memdel(ap->content);
		free(ap);
		ap = NULL;
	}
}
