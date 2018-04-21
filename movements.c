#include "fdf.h"
#include <math.h>
void	shift(t_map *map, int shift, char axis)
{
	 int i;
	 int j;

	 i = -1;
    if (axis == 'x')
         while (++i < map->row)
         {
            j = -1;
            while (++j < map->col)
				map->offset[i][j].x += shift;
         }
    else if (axis == 'y')
        while (++i < map->row)
        {
            j = -1;
            while (++j < map->col)
				map->offset[i][j].y += shift;
        }
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
			map->offset[i][j].x = (int)round(map->offset[i][j].x * cos(map->wz) + map->offset[i][j].y * sin(map->wz)) + SCREEN_WIDTH/2;
			map->offset[i][j].y = (int)round(map->offset[i][j].y * cos(map->wz) - map->offset[i][j].x * sin(map->wz)) + SCREEN_HEIGHT/2;
			map->offset[i][j].color = map->original[i][j].color;
		}
	}

}
