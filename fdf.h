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
#define MOVE_UP_KEY 13
#define MOVE_UP_KEY_LINUX 119
#define MOVE_DOWN_KEY 1
#define MOVE_DOWN_KEY_LINUX 115
#define MOVE_LEFT_KEY 0
#define MOVE_LEFT_KEY_LINUX 97
#define MOVE_RIGHT_KEY 2
#define MOVE_RIGHT_KEY_LINUX 100
#define X_ROTATION_POSITIVE 124
#define X_ROTATION_POSITIVE_LINUX 65363
#define Y_ROTATION_POSITIVE 126
#define Y_ROTATION_POSITIVE_LINUX 65362
#define Z_ROTATION_POSITIVE 7
#define Z_ROTATION_POSITIVE_LINUX 122
#define X_ROTATION_NEGATIVE 123
#define X_ROTATION_NEGATIVE_LINUX 65361
#define Y_ROTATION_NEGATIVE 125
#define Y_ROTATION_NEGATIVE_LINUX 65364
#define Z_ROTATION_NEGATIVE 6
#define Z_ROTATION_NEGATIVE_LINUX 120
#define X_AXIS 'x'
#define Y_AXIS 'y'
#define ZOOM_IN_KEY 24
#define ZOOM_IN_KEY_LINUX 61
#define ZOOM_OUT_KEY 27
#define ZOOM_OUT_KEY_LINUX 45
#define ESC 53
#define ESC_LINUX 65307
#define RED_KEY_LINUX 114
#define GREEN_KEY_LINUX 103
#define BLUE_KEY_LINUX 98

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
	t_dot		**base;
	t_dot		**offset;
	void		*window;
	void		*mlx_ptr;
	int			zoom;
	int			color;
	double wx;
	double wy;
	double wz;
    int offset_x;
    int offset_y;
}				t_map;

t_map	*read_map(int fd, t_list **list);
void	del(void *cont, size_t size);
int 	on_key_press(int key, t_map *map);
int		set_color(t_map *map, unsigned char red, unsigned char green, unsigned char blue);
void	shift(t_map *map);
int put_image(void *mlx_ptr, void *window, t_map *map);
void    zoom_map(t_map *map);
int		line(t_dot A, t_dot B, void *ret, void *window);
void 	rotate(t_map *map);
int		close_window();

#endif