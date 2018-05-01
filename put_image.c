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

int			put_legend(t_map *map)
{
	mlx_string_put(map->mlx_ptr, map->window, 40, 40, 0xFFFFFF,
		"ZOOM: +/-");
	mlx_string_put(map->mlx_ptr, map->window, 40, 60, 0xFFFFFF,
		"ROTATE X: TOP/BOTTOM ARROWS");
	mlx_string_put(map->mlx_ptr, map->window, 40, 80, 0xFFFFFF,
		"ROTATE Y: RIGHT/LEFT ARROWS");
	mlx_string_put(map->mlx_ptr, map->window, 40, 100, 0xFFFFFF,
		"ROTATE Z: z/x");
	mlx_string_put(map->mlx_ptr, map->window, 40, 120, 0xFFFFFF,
		"MOVE LEFT/RIGHT: a/d");
	mlx_string_put(map->mlx_ptr, map->window, 40, 140, 0xFFFFFF,
		"MOVE UP/DOWN: w/s");
	mlx_string_put(map->mlx_ptr, map->window, 40, 160, 0xFFFFFF,
		"SHOW/HIDE HELP: h");
	return (0);
}

void		set_color(int *map, unsigned char red,
	unsigned char green, unsigned char blue)
{
	if (!map)
		return ;
	*map = 65536 * red + 256 * green + blue;
}

int			put_image(t_map *map)
{
	int		i;
	int		j;
	t_dot	d;

	if (!map || !map->mlx_ptr || !map->window)
		return (1);
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			d = map->mod[i][j];
			if (j != map->col - 1)
				d.color = line(d, map->mod[i][j + 1], map);
			if (i != map->row - 1)
				d.color = line(d, map->mod[i + 1][j], map);
			if (d.x > -1 && d.y > -1 && d.x < SCREEN_WIDTH &&
					d.y < SCREEN_HEIGHT)
				mlx_pixel_put(map->mlx_ptr, map->window, d.x, d.y, d.color);
		}
	}
	if (map->show_legend)
		put_legend(map);
	return (0);
}
