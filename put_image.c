/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <sahafono@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 14:51:00 by sahafono          #+#    #+#             */
/*   Updated: 2018/04/30 14:51:00 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int put_image(t_map *map)
{
	int i;
	int j;
	t_dot cur;

	if (!map || !map->mlx_ptr || !map->window)
		return (1);
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			cur = map->offset[i][j];
			if (j != map->col - 1)
				cur.color = line(cur, map->offset[i][j + 1], map);
			if (i != map->row - 1)
				cur.color = line(cur, map->offset[i + 1][j], map);
			mlx_pixel_put(map->mlx_ptr, map->window, cur.x, cur.y, cur.color);
		}
	}
	return (0);
}
