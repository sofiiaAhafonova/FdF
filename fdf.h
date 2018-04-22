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
#include <math.h>
#define PI 3.14159265
#define DEEGRE PI/180
#define SHIFT 5
#define SCREEN_WIDTH 1800
#define SCREEN_HEIGHT 1000
#define ZERO_LEVEL_COLOR 300200000
typedef struct	s_dot
{
	int x;
	int y;
	int z;
	int color;
}				t_dot;

typedef struct	s_map
{
	int row;
	int col;
	t_dot		**original;
	t_dot		**offset;
	void		*window;
	void		*mlx_ptr;
	int			zoom;
	double wx;
	double wy;
	double wz;
    int offset_x;
    int offset_y;
}				t_map;

t_map	*read_map(int fd, t_list **list);
void	del(void *cont, size_t size);
int 	on_key_press(int key, t_map *map);
void	shift(t_map *map, int shift, char axis);
int put_image(void *mlx_ptr, void *window, t_map *map);
void    zoom_map(t_map *map);
void line(t_dot A, t_dot B, void *ret, void *window);
void 	rotate(t_map *map);
int		close_window();

#endif