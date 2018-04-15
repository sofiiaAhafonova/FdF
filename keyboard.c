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

int 	on_key_press(int key, t_map *map)
{
	ft_putnbr(key);
	ft_putendl("");
	/*right arrow*/
	if (key == 65363 || key == 124)
		shift_x(map, 1);
	/*top arrow*/
	if (key == 65362 || key == 126)
		;
	/*left arrow*/
	if (key == 65361 || key == 123)
		;
	/*bottom arrow*/
	if (key == 65364 || key == 125)
		;
	/*minus*/
	if (key == 45)
		;
	;
	/*plus*/
	if (key == 61)
		;
	if (key == 53 || key == 65307)
		exit(EXIT_SUCCESS);
	return (0);
}
