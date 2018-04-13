/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <sahafono@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 21:17:00 by sahafono          #+#    #+#             */
/*   Updated: 2018/03/11 21:17:00 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct s_dot
{

};
typedef struct  s_map
{
    unsigned int row;
    unsigned int col;
    t_list      *list;
}               t_map;

t_map 	*read_map(int fd, t_list **list);
void 	del(void *cont, size_t size);
int     **list_to_arr(t_map *map);
int 	on_key_press(int key, void *param);

#endif