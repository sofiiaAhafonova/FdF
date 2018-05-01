/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <sahafono@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 14:47:00 by sahafono          #+#    #+#             */
/*   Updated: 2018/05/01 15:12:57 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot	module(t_dot a, t_dot b)
{
	t_dot d;

	d.x = abs(b.x - a.x);
	d.y = abs(b.y - a.y);
	return (d);
}

t_dot	direction(t_dot a, t_dot b)
{
	t_dot s;

	s.x = a.x < b.x ? 1 : -1;
	s.y = a.y < b.y ? 1 : -1;
	return (s);
}

int		mid_clr(t_dot a, t_dot b)
{
	int base_color;
	int color;

	if (a.color > b.color)
		base_color = b.color;
	else
		base_color = a.color;
	if (base_color <= -10)
		set_color(&color, 0, 100, 0);
	else if (base_color < -2)
		set_color(&color, 0, 102, 0);
	else if (base_color >= -2 && base_color <= 2)
		set_color(&color, 0, 153, 0);
	else if (base_color > 2 && base_color < 10)
		set_color(&color, 178, 255, 102);
	else if (base_color >= 10 && base_color < 20)
		set_color(&color, 255, 255, 102);
	else if (base_color >= 20 && base_color < 50)
		set_color(&color, 255, 165, 0);
	else if (base_color >= 50 && base_color < 70)
		set_color(&color, 255, 140, 0);
	else
		set_color(&color, 255, 99, 71);
	return (color);
}

void	print_dot(t_dot a, t_dot b)
{
	if (a.x > -1 && a.y > -1 && a.x < SCREEN_WIDTH && a.y < SCREEN_HEIGHT)
		mlx_pixel_put(map->mlx_ptr, map->window, a.x, a.y, mid_clr(a, b));
}

int		line(t_dot a, t_dot b, t_map *map)
{
	t_dot error;
	t_dot d;
	t_dot s;

	d = module(a, b);
	s = direction(a, b);
	error.x = (d.x > d.y ? d.x : -d.y) / 2;
	while (1)
	{
		print_dot(a, b);
		if (a.x == b.x && a.y == b.y)
			break ;
		error.y = error.x;
		if (error.y > -d.x)
		{
			error.x -= d.y;
			a.x += s.x;
		}
		if (error.y < d.y)
		{
			error.x += d.x;
			a.y += s.y;
		}
	}
	return (medium_color(a, b));
}
