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

int     *str_to_arr(char *str, int col)
{
    char **tmp;
    int *arr;
    int i;

    if (!str || col < 1 || !( tmp = ft_strsplit(str, ' ')))
        return (0);
    arr = (int*)malloc(sizeof(int) *col);
    i = -1;
    while (++i < col)
        arr[i] = ft_atoi(tmp[i]);
    while (--i > -1)
        ft_strdel(&tmp[i]);
    free(tmp);
    return (arr);
}

int     **list_to_arr(t_map *map)
{
    int **arr;
    int i;
    t_list *node;

    if (!map || !(arr = (int**)malloc(sizeof(int*)*map->row)))
        return (0);
    node = map->list;
    i = map->row - 1;
    while (i > -1 && node)
    {
        arr[i] = node->content;
        if (!arr[i])
        {
            while (++i < map->row)
                free(arr[i]);
            free(arr);
            return (0);
        }
        node = node->next;
        i--;
    }
    return (arr);
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
        node = ft_lstnew(str_to_arr(buf, num), sizeof(int) * (num + 1));
        ft_lstadd(list, node);
		ft_strdel(&buf);
	}
	if (!list)
		return (0);
	return (map_params(num, *list));
}
