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
			map->offset[i][j].x = (int)round( (map->offset[i][j].x * cos(map->z_angle) + map->offset[i][j].y * sin(map->z_angle))) ;
			map->offset[i][j].y = (int)round( (map->offset[i][j].y * cos(map->z_angle) - map->offset[i][j].x * sin(map->z_angle)));
			map->offset[i][j].color = map->original[i][j].color;
		}
	}
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
			map->offset[i][j].y = (int)round(map->original[i][j].y *cos(map->x_angle) + map->original[i][j].z * sin(map->x_angle )) + map->y0 - map->offset_y;
			map->offset[i][j].z = (int)round(map->original[i][j].z * cos(map->x_angle) - map->original[i][j].y * sin(map->x_angle )) + map->z0;
			map->offset[i][j].color = map->original[i][j].color;
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
			map->offset[i][j].x = (int)round (map->original[i][j].x * cos(map->y_angle) + map->original[i][j].z * sin(map->y_angle))  + map->x0 -  map->offset_x;
			map->offset[i][j].z = (int)round (map->original[i][j].z * cos(map->y_angle) - map->original[i][j].x * sin(map->y_angle)) + map->z0;
			map->offset[i][j].color = map->original[i][j].color;
		}
	}
}
