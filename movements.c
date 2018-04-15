#include "fdf.h"

void	shift_x(t_map *map, int shift)
{
	unsigned int k;
	unsigned int len;

	k = 0;
	len = map->col * map->row;
	while (k < len)
	{
        map->dots[k].x += shift;
		k++;
	}
    mlx_clear_window(map->mlx_ptr, map->window);
    put_image(map->mlx_ptr, map->window, map);
}

void	shift_y(t_map *map, int shift)
{
	unsigned int k;
	unsigned int len;

	k = 0;
	len = map->col * map->row;
	while (k < len)
	{
		map->dots[k].y += shift;
		k++;
	}
}