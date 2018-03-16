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
#include "fdf.h"
#include <fcntl.h>

void	print_lst(t_list *list)
{

	while (list)
	{
        ft_putendl(list->content);
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
		free(cont);
}

t_map   *map_params(int col, t_list *list)
{
    t_map   *map;
    t_list  *cur;

    if (col <= 0)
        return (NULL);
    map = (t_map*)malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->col = (unsigned int)col;
    map->row = 0;
    cur = list;
    while (cur)
    {
        cur = cur->next;
        (map->row)++;
    }
    map->list = list;
    return (map);
}
t_map	*read_map(int fd, t_list **list)
{
	t_list	*node;
	char	*buf;;
	int num;
	int first;

	num = -1;
	first = -1;
	while (get_next_line(fd, &buf) == 1)
	{
		if (first == -1 && num != -1)
			first = num;
		if (!(num = is_num(buf)) || (first != -1 && first != num))
		{
			ft_strdel(&buf);
            list ? ft_lstdel(list, &del) : 0;
			return (0);
		}
        node = ft_lstnew(buf, ft_strlen(buf) + 1);
        ft_lstadd(list, node);
		ft_strdel(&buf);
	}
	if (!list)
		return (0);
	print_lst(*list);
	return (map_params(num, *list));
}
