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

#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
typedef struct	s_dot
{
	int x;
	int y;
	int z;
}				t_dot;

typedef struct	s_map
{
	unsigned int row;
	unsigned int col;
	t_dot		*dots;
	void		*window;
	void		*mlx_ptr;
	int			zoom;
}				t_map;

t_map	*read_map(int fd, t_list **list);
void	del(void *cont, size_t size);
int 	on_key_press(int key, t_map *map);
void	shift_x(t_map *map, int shift);
void	shift_y(t_map *map, int shift);
int put_image(void *mlx_ptr, void *window, t_map *map);
t_map *zoom_map(t_map *map);
void line(t_dot A, t_dot B, void *ret, void *window);
#endif