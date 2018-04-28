/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:29:36 by sahafono          #+#    #+#             */
/*   Updated: 2018/04/11 15:29:38 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include "minilibx_macos/mlx.h"
#include <stdlib.h>
#include "libft/libft.h"
#include <stdio.h>

int 	is_movement(int key)
{
	return (key == MOVE_UP_KEY || key == MOVE_UP_KEY_LINUX || key == MOVE_DOWN_KEY || key == MOVE_DOWN_KEY_LINUX || key == MOVE_LEFT_KEY || key == MOVE_LEFT_KEY_LINUX
	|| key == MOVE_RIGHT_KEY || key == MOVE_RIGHT_KEY_LINUX|| key == X_ROTATION_POSITIVE || key == X_ROTATION_POSITIVE_LINUX || key == Y_ROTATION_POSITIVE || key == Y_ROTATION_POSITIVE_LINUX
			|| key == Z_ROTATION_POSITIVE || key == Z_ROTATION_POSITIVE_LINUX || key == X_ROTATION_NEGATIVE || key == X_ROTATION_NEGATIVE_LINUX || key == Y_ROTATION_NEGATIVE ||
			key == Y_ROTATION_NEGATIVE_LINUX || key == Z_ROTATION_NEGATIVE || key == Z_ROTATION_NEGATIVE_LINUX || key == ZOOM_IN_KEY || key == ZOOM_IN_KEY_LINUX ||
	key == ZOOM_OUT_KEY || key == ZOOM_OUT_KEY_LINUX || key == ESC || key == ESC_LINUX);
}

void	original_size(t_map *map)
{
	int i;
	int j;
	t_dot cur;

	if (!map || map->zoom < 1)
		return ;
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			cur = map->base[i][j];
			cur.x = j;
			cur.y = i;
			cur.z /= map->zoom;
			map->base[i][j] = cur;
		}
	}
}

int		set_color(t_map *map, unsigned char red, unsigned char green, unsigned char blue)
{
	if (!map)
		return (-1);
	map->color = 65536 * red + 256 * green + blue;
}
int		close_window()
{
	exit(EXIT_SUCCESS);
}

int 	on_key_press(int key, t_map *map)
{
//	ft_putnbr(key);
//	ft_putendl("");
	if (key == ESC || key == ESC_LINUX)
		return (close_window());
	if (!is_movement(key))
		return (0);
	/*w*/
	if (key == MOVE_UP_KEY_LINUX || key == MOVE_UP_KEY)
		map->offset_y -= SHIFT;
	/*a*/
	if (MOVE_LEFT_KEY == key || key == MOVE_LEFT_KEY_LINUX)
		map->offset_x -= SHIFT;
	/*d*/
	if (key == MOVE_RIGHT_KEY || key == MOVE_RIGHT_KEY_LINUX)
		map->offset_x += SHIFT;
	/*s*/
	if (key == MOVE_DOWN_KEY || key == MOVE_DOWN_KEY_LINUX)
		map->offset_y += SHIFT;
	/*right arrow*/
	if (key == X_ROTATION_POSITIVE_LINUX || key == X_ROTATION_POSITIVE)
		map->wx += 2*DEEGRE;
	/*top arrow*/
	if (key == Y_ROTATION_POSITIVE || key == Y_ROTATION_POSITIVE_LINUX)
		map->wy += 2*DEEGRE;
	/*left arrow*/
	if (key == X_ROTATION_NEGATIVE || key == X_ROTATION_NEGATIVE_LINUX)
		map->wx -=2* DEEGRE;
	/*bottom arrow*/
	if (key == Y_ROTATION_NEGATIVE || key == Y_ROTATION_NEGATIVE_LINUX)
		map->wy -= 2*DEEGRE;
	/*z*/
	if (key == Z_ROTATION_NEGATIVE || key == Z_ROTATION_NEGATIVE_LINUX)
		map->wz -= 2*DEEGRE;
	/*x*/
	if (key == Z_ROTATION_POSITIVE || key == Z_ROTATION_POSITIVE_LINUX)
		map->wz += 2*DEEGRE;
	/*minus or plus*/
	if (key == RED_KEY_LINUX)
		;
//		map->color > 0;
	if (key == ZOOM_IN_KEY || key == ZOOM_IN_KEY_LINUX || key == ZOOM_OUT_KEY || key == ZOOM_OUT_KEY_LINUX)
	{
		original_size(map);
		(key == ZOOM_OUT_KEY || key == ZOOM_OUT_KEY_LINUX) ? map->zoom-- : map->zoom++;
		zoom_map(map);
	}
	rotate(map);
	shift(map);
	shift(map);
	mlx_clear_window(map->mlx_ptr, map->window);
	put_image(map->mlx_ptr, map->window, map);
	return (0);
}
