/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <sahafono@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 14:53:00 by sahafono          #+#    #+#             */
/*   Updated: 2018/05/01 14:49:57 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 		del(void *cont, size_t size)
{
	if (size)
		free(cont);
}

void	remove_map(t_map *map)
{
	int i;

	i = -1;
	if (!map)
		return ;
	while (++i < map->row)
	{
		if (map->base)
			free(map->base[i]);
		if (map->mod)
			free(map->mod[i]);
	}
	if (map->base)
		free(map->base);
	if (map->mod)
		free(map->mod);
	if (map->mlx_ptr && map->window)
		mlx_destroy_window(map->mlx_ptr, map->window);
	if (map->mlx_ptr)
		free(map->mlx_ptr);
	free(map);
}
