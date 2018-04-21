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
                map->original[i][j].x += shift;
         }
    else if (axis == 'y')
        while (++i < map->row)
        {
            j = -1;
            while (++j < map->col)
                map->original[i][j].y += shift;
        }
}

void rotate_z(t_map *map, double angle)
{
	int i;
	int j;

	i = -1;
	map->z_angle += angle;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			map->original[i][j].x = (int)round( ((map->zoom *j - map->offset_y) * cos(map->z_angle) + (map->zoom *i - map->offset_x) * sin(map->z_angle))) + map->x0;
			map->original[i][j].y = (int)round( ((map->zoom *i - map->offset_x) * cos(map->z_angle) - (map->zoom *j - map->offset_y) * sin(map->z_angle)))+ map->y0;
		}
	}
	rotate_x(map, 0);
    rotate_y(map, 0);

}

void rotate_x(t_map *map, double angle)
{
	int i;
	int j;

	i = -1;
	map->x_angle += angle;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			map->original[i][j].y = (int)round((map->zoom *i - map->offset_y)*cos(map->x_angle) +
										   (map->original[i][j].z - map->z0) * sin(map->x_angle )) + map->y0 - map->offset_y;
//			map->original[i][j].z = (int)round((map->original[i][j].z - map->z0) * cos(map->x_angle) -
//                                                       (map->zoom *i - map->offset_x)* sin(map->x_angle )) + map->z0;
		}
	}
}
void rotate_y(t_map *map, double angle)
{
	int i;
	int j;

	i = -1;
	map->y_angle += angle;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			map->original[i][j].x = (int)round ((j * map->zoom - map->offset_y)* cos(map->y_angle) +
											(map->original[i][j].z - map->z0)* sin(map->y_angle))  + map->x0 -  map->offset_x;
//			map->original[i][j].z = (int)round ((map->original[i][j].z - map->z0) * cos(map->y_angle) -
//                                                        (j * map->zoom - map->offset_y) * sin(map->y_angle)) + map->z0;
		}
	}
//	map->x0 = map->original[0][0].x;
//	map->z0 = map->original[0][0].z;
}
