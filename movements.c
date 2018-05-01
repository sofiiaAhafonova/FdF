/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:30:03 by sahafono          #+#    #+#             */
/*   Updated: 2018/05/01 14:31:23 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		zoom_map(t_map *map)
{
	int		i;
	int		j;
	t_dot	cur;

	if (!map || map->zoom < 1)
		return ;
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			cur = map->base[i][j];
			cur.x = j * map->zoom - (map->col * map->zoom) / 2;
			cur.y = i * map->zoom - (map->row * map->zoom) / 2;
			cur.z *= map->zoom;
			map->base[i][j] = cur;
		}
	}
}

void		original_size(t_map *map)
{
	int		i;
	int		j;
	t_dot	cur;

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

double		*trigonometric_func(t_map *map)
{
	double	*trigonometric_func;

	trigonometric_func = ft_memalloc(sizeof(double) * 6);
	trigonometric_func[0] = sin(map->wx);
	trigonometric_func[1] = cos(map->wx);
	trigonometric_func[2] = sin(map->wy);
	trigonometric_func[3] = cos(map->wy);
	trigonometric_func[4] = sin(map->wz);
	trigonometric_func[5] = cos(map->wz);
	return (trigonometric_func);
}

void		rotate_dot(t_dot *mod, t_dot base, t_map *map, double *ar)
{
	int	cur;

	mod->y = (int)(base.y * ar[1] - base.z * ar[0]);
	mod->z = (int)(base.z * ar[1] + base.y * ar[0]);
	mod->x = (int)(base.x * ar[3] + base.z * ar[2]);
	mod->z = (int)(mod->z * ar[3] - mod->x * ar[2]);
	cur = mod->x;
	mod->x = (int)(cur * ar[5] - mod->y * ar[4]) + map->offset_x;
	mod->y = (int)(mod->y * ar[5] + cur * ar[4]) + map->offset_y;
}

void		rotate(t_map *map)
{
	int		i;
	int		j;
	double	*ar;

	i = -1;
	ar = trigonometric_func(map);
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			rotate_dot(&map->mod[i][j], map->base[i][j], map, ar);
			map->mod[i][j].color = map->base[i][j].z / map->zoom;
		}
	}
	free(ar);
}
