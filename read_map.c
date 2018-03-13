/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <sahafono@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 21:00:00 by sahafono          #+#    #+#             */
/*   Updated: 2018/03/11 21:00:00 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>

void	print_lst(t_list *list)
{
	while (list)
	{
		ft_putendl_fd((char*)list->content, 0);
		list = list->next;
	}
}

int 	is_num(char *str)
{
	size_t i;
	int counter;
	size_t len;

	i = 0;
	counter = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-')
			return (0);
		if (i + 1 < len && str[i] == '-' && !ft_isdigit(str[i + 1]))
			return(0);
		if (i > 0 && str[i] == '-' && str[i - 1] != ' ')
			return(0);
		if (i > 0 && str[i] == ' ' && ft_isdigit(str[i - 1]))
			counter++;
		i++;
	}
	if (ft_isdigit(str[i - 1]))
		counter++;
	return (counter);
}

void 	del(void *cont, size_t size)
{
	if (size)
		//free(&cont);
		ft_putendl("Del list");
}

int 	read_map(int fd)
{
	t_list	*list;
	t_list	*node;
	char	*buf;;
	int num;
	int first;
	list = NULL;

	num = -1;
	first = -1;
	while (get_next_line(fd, &buf) == 1)
	{
		node = ft_lstnew(ft_strtrim(buf), ft_strlen(buf));
		if (first == -1 && num != -1)
			first = num;
		if (!(num = is_num(buf)) || (first != -1 && first != num))
		{
			if (buf)
				ft_strdel(&buf);
			if (list)
				ft_lstdel(&list, &del);
			return (0);
		}
		else
			ft_lstadd(&list, node);
		ft_strdel(&buf);
	}
	print_lst(list);
	return (1);
}
