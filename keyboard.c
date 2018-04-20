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

int 	is_movement(int key)
{
	return (key == 65363 || key == 124 || key == 65362 || key == 126 || key == 65361 || key == 123
	|| key == 65364 || key == 125 || key == 120 || key == 122 || key == 45 || key == 61);
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
			cur = map->dots[i][j];
			cur.x /= map->zoom;
			cur.y /= map->zoom;
			cur.z /= map->zoom;
			map->dots[i][j] = cur;
		}
	}
}
int 	on_key_press(int key, t_map *map)
{
	ft_putnbr(key);
	ft_putendl("");
	/*right arrow*/
	if (key == 65363 || key == 124)
		rotate_x(map, 0.001);
	/*top arrow*/
	if (key == 65362 || key == 126)
		rotate_y(map, 0.001);
	/*left arrow*/
	if (key == 65361 || key == 123)
		rotate_x(map, -0.001);
	/*bottom arrow*/
	if (key == 65364 || key == 125)
		rotate_y(map, -0.001);
	/*z*/
	if (key == 120 /*|| key == 123*/)
		rotate_z(map, -0.001);
	/*x*/
	if (key == 122 /*|| key == 125*/)
		rotate_z(map, 0.001);
	/*minus or plus*/
	if (key == 45 || key == 61)
	{
		key == 45 ? map->zoom-- : map->zoom++;
		original_size(map);
		map = zoom_map(map);
	}
	if (key == 53 || key == 65307)
		exit(EXIT_SUCCESS);
	if (is_movement(key))
	{
		mlx_clear_window(map->mlx_ptr, map->window);
		put_image(map->mlx_ptr, map->window, map);
	}
	return (0);
}
