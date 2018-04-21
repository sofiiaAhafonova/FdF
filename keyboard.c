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
	|| key == 65364 || key == 125 || key == 120 || key == 122
			|| key == 27 || key == 24 || key == 45 || key == 61 || key == 7 ||
			key == 6 || key == 1 || key == 2 || key == 0 || key == 13);
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
			cur = map->original[i][j];
			cur.x = (cur.x) / map->zoom;
			cur.y = (cur.y) /map->zoom;
			cur.z  = (cur.z) /map->zoom;
			map->original[i][j] = cur;
		}
	}
}
int 	on_key_press(int key, t_map *map)
{
	ft_putnbr(key);
	ft_putendl("");
	/*w*/
	if (key == 13)
		shift(map, -SHIFT, 'y');
	/*a*/
	if (key == 0)
		shift(map, -SHIFT, 'x');
	/*d*/
	if (key == 2)
		shift(map, SHIFT, 'x');
	/*s*/
	if (key == 1)
		shift(map, SHIFT, 'y');
	/*right arrow*/
	if (key == 65363 || key == 124)
		rotate_x(map,DEEGRE);
	/*top arrow*/
	if (key == 65362 || key == 126)
		rotate_y(map,DEEGRE);
	/*left arrow*/
	if (key == 65361 || key == 123)
		rotate_x(map, -DEEGRE);
	/*bottom arrow*/
	if (key == 65364 || key == 125)
		rotate_y(map, -DEEGRE);
	/*z*/
	if (key == 120 || key == 6)
		rotate_z(map, -DEEGRE);
	/*x*/
	if (key == 122 || key == 7)
		rotate_z(map, DEEGRE);
	/*minus or plus*/
	if (key == 27 || key == 24 || key == 45 || key == 61)
	{
		original_size(map);
		(key == 45 || key == 27) ? map->zoom-- : map->zoom++;
		zoom_map(map);
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
