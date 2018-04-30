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

#include "libft/libft.h"
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

int     *str_to_arr(char *str, int col)
{
    char **tmp;
    int *arr;
    int i;

    if (!str || col < 1 || !( tmp = ft_strsplit(str, ' ')))
        return (0);
    arr = (int*)malloc(sizeof(int) * col);
    i = -1;
    while (++i < col)
        arr[i] = ft_atoi(tmp[i]);
    while (--i > -1)
        ft_strdel(&tmp[i]);
    free(tmp);
    return (arr);
}

t_dot   **from_str_to_dots(t_list *list, int row, int col, int color)
{
    t_dot   **dots;
    t_list  *head;
    int     i;
    int     j;

    if (!list || !(dots = (t_dot**)malloc(sizeof(t_dot*) * (row))))
        return (NULL);
    head = list;
    i = row;
    while (list && --i > -1)
    {
        if (!(dots[i] = (t_dot*)malloc(sizeof(t_dot)* col)))
			return (NULL);
        j = -1;
        while (++j < col)
        {
            dots[i][j].x = j;
            dots[i][j].y = i;
            dots[i][j].z = ((int*)list->content)[j];
        }
        list = list->next;
    }
    ft_lstdel(&head, &del);
    return (dots);
}

t_map   *map_params(int col, t_list *list)
{
    t_map   *map;
    t_list  *cur;

    if (col <= 0 || !list)
        return (NULL);
    map = (t_map*)malloc(sizeof(t_map));
    if (!map)
        return (NULL);
    map->col = col;
    map->row = 0;
	set_color(&(map->color),0,128,128);
    cur = list;
    while (cur)
    {
        cur = cur->next;
        (map->row)++;
    }
    map->base = from_str_to_dots(list,map->row, map->col, map->color);
    return (map);
}

t_map	*read_map(int fd, t_list **list)
{
	t_list	*node;
	char	*buf;;
	int num;
	int first;
	int *ar;

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
		ar = str_to_arr(buf, num);
        node = ft_lstnew(ar, sizeof(int) * (num));
        free(ar);
        ft_lstadd(list, node);
		ft_strdel(&buf);
	}
	return (map_params(num, *list));
}
