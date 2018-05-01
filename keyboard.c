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
	key == ZOOM_OUT_KEY || key == ZOOM_OUT_KEY_LINUX || key == ESC || key == ESC_LINUX || key == HELP_KEY_LINUX);
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

int		close_window(t_map *map)
{
	remove_map(map);
	exit(EXIT_SUCCESS);
}

int		zoom_keys(int key, t_map *map)
{
	if (key != ZOOM_IN_KEY && key != ZOOM_IN_KEY_LINUX &&
		key != ZOOM_OUT_KEY && key != ZOOM_OUT_KEY_LINUX)
		return (0);
	original_size(map);
	if (map->zoom > 1 && (key == ZOOM_OUT_KEY || key == ZOOM_OUT_KEY_LINUX))
		map->zoom--;
	else if (map->zoom > 0 && (key == ZOOM_IN_KEY || key == ZOOM_IN_KEY_LINUX))
		map->zoom++;
	else
		return (1);
	zoom_map(map);
	return (0);
}

int 	on_key_press(int key, t_map *map)
{
	if (!map)
		return (0);
	if (key == ESC || key == ESC_LINUX)
		return (close_window(map));
	if (!is_movement(key))
		return (0);
	if (key == MOVE_UP_KEY_LINUX || key == MOVE_UP_KEY)
		map->offset_y -= SHIFT;
	else if (MOVE_LEFT_KEY == key || key == MOVE_LEFT_KEY_LINUX)
		map->offset_x -= SHIFT;
	else if (key == MOVE_RIGHT_KEY || key == MOVE_RIGHT_KEY_LINUX)
		map->offset_x += SHIFT;
	else if (key == MOVE_DOWN_KEY || key == MOVE_DOWN_KEY_LINUX)
		map->offset_y += SHIFT;
	else if (key == X_ROTATION_POSITIVE_LINUX || key == X_ROTATION_POSITIVE || key == X_ROTATION_NEGATIVE || key == X_ROTATION_NEGATIVE_LINUX)
		map->wx  = key == X_ROTATION_POSITIVE_LINUX || key == X_ROTATION_POSITIVE  ? map->wx + 2*DEGREE : map->wx - 2*DEGREE;
	else if (key == Y_ROTATION_POSITIVE || key == Y_ROTATION_POSITIVE_LINUX || key == Y_ROTATION_NEGATIVE || key == Y_ROTATION_NEGATIVE_LINUX)
		map->wy = key == Y_ROTATION_POSITIVE || key == Y_ROTATION_POSITIVE_LINUX ? map->wy + 2*DEGREE : map->wy - 2*DEGREE;
	else if (key == Z_ROTATION_NEGATIVE || key == Z_ROTATION_NEGATIVE_LINUX || key == Z_ROTATION_POSITIVE || key == Z_ROTATION_POSITIVE_LINUX)
		map->wz = key == Z_ROTATION_POSITIVE || key == Z_ROTATION_POSITIVE_LINUX ? map->wz + 2*DEGREE : map->wz - 2*DEGREE;
	else if (zoom_keys(key, map))
		return (0);
	else if (key == HELP_KEY || key == HELP_KEY_LINUX)
		map->show_legend = map->show_legend ? 0 : 1;
	rotate(map);
	mlx_clear_window(map->mlx_ptr, map->window);
	put_image(map);
	return (0);
}
