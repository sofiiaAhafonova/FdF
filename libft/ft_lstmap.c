/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:55:39 by sahafono          #+#    #+#             */
/*   Updated: 2017/12/05 12:50:19 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;
	t_list *tmp;

	if (!lst || !f)
		return (NULL);
	res = f(lst);
	lst = lst->next;
	tmp = res;
	while (lst)
	{
		tmp->next = f(lst);
		if (tmp->next)
			tmp = tmp->next;
		lst = lst->next;
	}
	return (res);
}
