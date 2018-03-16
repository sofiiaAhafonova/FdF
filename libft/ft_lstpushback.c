/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:37:54 by sahafono          #+#    #+#             */
/*   Updated: 2017/12/27 16:38:25 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **alst, t_list *new)
{
	t_list *cur;

	if (alst == NULL || *alst == NULL || new == NULL)
	{
		ft_lstadd(alst, new);
		return ;
	}
	cur = *alst;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new;
	cur->next->next = NULL;
}
