/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <sahafono@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 14:48:00 by sahafono          #+#    #+#             */
/*   Updated: 2018/04/30 14:48:00 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int start_zoom(t_map *map)
{
	if (map->row <= 10 && map->col <= 30)
		return (50);
	if (map->row <= 20 && map->col <= 40)
		return (40);
	if (map->row <= 30 && map->col <= 30)
		return (30);
	if (map->row <= 40 && map->col <= 50)
		return (25);
	if (map->row <= 60 && map->col <= 80)
		return (20);
	if (map->row <= 80 && map->col <= 110)
		return (15);
	if (map->row <= 100 && map->col <= 160)
		return (10);
	if (map->row <= 200 && map->col <= 340)
		return (6);
	return (2);
}

int initialize_map(t_map *map)
{
	if (!(map->mlx_ptr = mlx_init()))
		return (print_error("mlx init error"));
	if (!(map->window = mlx_new_window(map->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "FdF")))
		return (print_error("window creation error"));
	map->zoom = start_zoom(map);
	zoom_map(map);
	map->offset = (t_dot**)malloc(sizeof(t_dot *) * map->row);
	int i = -1;
	while (++i < map->row)
		map->offset[i] = malloc(sizeof(t_dot)*map->col);
	map->offset_x = SCREEN_WIDTH / 2;
	map->offset_y =  SCREEN_HEIGHT / 2;
	map->wz = 0 *  DEGREE;
	map->wy = 2 *  DEGREE;
	map->wx = 2 *  DEGREE;
	map->show_legend = 1;
	map->scale_z = 1;
    return (0);
}
