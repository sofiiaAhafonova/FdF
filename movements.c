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