#include "fdf.h"
#include <math.h>
void	shift_x(t_map *map, int shift)
{
	 int i;
	 int j;

	 i = -1;
	 while (++i < map->row)
	 {
	 	j = -1;
	 	while (++j < map->col)
	 		map->dots[i][j].x += shift;
	 }
}

void	shift_y(t_map *map, int shift)
{
	int i;
	int j;

	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
			map->dots[i][j].y += shift;
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
			map->dots[i][j].x = (int)round(map->zoom * j * cos(map->z_angle) + map->zoom * i * sin(map->z_angle)) + map->x0;
			map->dots[i][j].y = (int)round(map->zoom * i * cos(map->z_angle) - map->zoom * j * sin(map->z_angle))+ map->y0;
		}
	}
	map->y0 = map->dots[0][0].y;
	map->x0 = map->dots[0][0].x;
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
			map->dots[i][j].y = (int)round(i * map->zoom *cos(map->x_angle) +
										   (map->dots[i][j].z - map->z0) * sin(map->x_angle )) + map->y0;
			map->dots[i][j].z = (int)round((map->dots[i][j].z - map->z0) * cos(map->x_angle) -
									  map->zoom * i * sin(map->x_angle )) + map->z0;
		}
	}
	map->y0 = map->dots[0][0].y;
	map->z0 = map->dots[0][0].z;
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
			map->dots[i][j].x = (int)round (j * map->zoom * cos(map->y_angle) +
											(map->dots[i][j].z - map->z0)* sin(map->y_angle))  + map->x0;
			map->dots[i][j].z = (int)round ((map->dots[i][j].z - map->z0) * cos(map->y_angle) -
											j * map->zoom * sin(map->y_angle)) + map->z0;
		}
	}
	map->x0 = map->dots[0][0].x;
	map->z0 = map->dots[0][0].z;
}
