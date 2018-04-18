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
	|| key == 65364 || key == 125 || key == 120 || key == 122);
}
int 	on_key_press(int key, t_map *map)
{
	ft_putnbr(key);
	ft_putendl("");
	/*right arrow*/
	if (key == 65363 || key == 124)
		rotate_x(map, DEEGRE);
	/*top arrow*/
	if (key == 65362 || key == 126)
		rotate_y(map, DEEGRE);
	/*left arrow*/
	if (key == 65361 || key == 123)
		rotate_x(map, -DEEGRE);
	/*bottom arrow*/
	if (key == 65364 || key == 125)
		rotate_y(map, DEEGRE);
	/*z*/
	if (key == 120 /*|| key == 123*/)
		rotate_z(map, -DEEGRE);
	/*x*/
	if (key == 122 /*|| key == 125*/)
		rotate_z(map, DEEGRE);
	/*minus*/
	if (key == 45)
		;
	;
	/*plus*/
	if (key == 61)
		;
	if (key == 53 || key == 65307)
		exit(EXIT_SUCCESS);
	if (is_movement(key))
	{
		mlx_clear_window(map->mlx_ptr, map->window);
		put_image(map->mlx_ptr, map->window, map);
	}
	return (0);
}
