/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <sahafono@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 14:47:00 by sahafono          #+#    #+#             */
/*   Updated: 2018/04/30 14:47:00 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot	module(t_dot A, t_dot B)
{
	t_dot D;

	D.x = abs(B.x - A.x);
	D.y = abs(B.y - A.y);
	return (D);
}

t_dot	direction(t_dot A, t_dot B)
{
	t_dot S;

	S.x = A.x < B.x ? 1 : -1;
	S.y = A.y < B.y ? 1 : -1;
	return (S);
}

void	set_color(int *map, unsigned char red, unsigned char green, unsigned char blue)
{
	if (!map)
		return ;
	*map = 65536 * red + 256 * green + blue;
}

int medium_color(t_dot A, t_dot B)
{
	int base_color;
	int color;

	if (A.color > B.color)
		base_color = B.color;
	else
		base_color = A.color;
	if (base_color <= - 10)
		set_color(&color, 0,100,0);
	else if (base_color < -2)
		set_color(&color, 0,102,0);
	else if (base_color >= -2 && base_color <= 2)
		set_color(&color, 0,153,0);
	else if (base_color > 2 && base_color < 10)
		set_color(&color, 178,255,102);
	else if (base_color >= 10 && base_color < 20)
		set_color(&color, 255,255,102);
	else if (base_color >= 20 && base_color < 50)
		set_color(&color, 255,165,0);
	else if (base_color >= 50 && base_color < 70)
		set_color(&color, 255,140,0);
	else if (base_color >= 70)
		set_color(&color,255,99,71);
	else
		color = 0;
	return (color);

}

int	line(t_dot A, t_dot B, t_map *map)
{
	int err;
	int e2;
	t_dot D;
	t_dot S;

	D = module(A, B);
	S = direction(A, B);
	err = (D.x > D.y ? D.x : -D.y) / 2;
	while(1)
	{
		mlx_pixel_put(map->mlx_ptr, map->window, A.x, A.y, medium_color(A, B));
		if (A.x == B.x && A.y == B.y)
			break;
		e2 = err;
		if (e2 > -D.x)
		{
			err -= D.y;
			A.x += S.x;
		}
		if (e2 < D.y)
		{
			err += D.x;
			A.y += S.y;
		}
	}
	return medium_color(A, B);
}