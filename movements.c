#include "fdf.h"
#include <math.h>

void	shift(t_map *map, int shift, char axis)
{
    if (axis == 'x')
        map->offset_x += shift;
    else if (axis == 'y')
		map->offset_y += shift;
}

void rotate(t_map *map)
{
	int i;
	int j;

	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			map->offset[i][j].y = (int)round(map->original[i][j].y *cos(map->wx) + map->original[i][j].z * sin(map->wx ));
			map->offset[i][j].z = (int)round(map->original[i][j].z * cos(map->wx) - map->original[i][j].y * sin(map->wx ));
			map->offset[i][j].x = (int)round(map->original[i][j].x * cos(map->wy) + map->original[i][j].z * sin(map->wy));
			map->offset[i][j].z = (int)round(map->offset[i][j].z * cos(map->wy) - map->offset[i][j].x * sin(map->wy));
			map->offset[i][j].x = map->offset_x + (int)round(map->offset[i][j].x * cos(map->wz) + map->offset[i][j].y * sin(map->wz));
			map->offset[i][j].y =  map->offset_y + (int)round(map->offset[i][j].y * cos(map->wz) - map->offset[i][j].x * sin(map->wz));
			map->offset[i][j].color = map->original[i][j].color;
		}
	}
}
