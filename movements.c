#include "fdf.h"
#include <math.h>
void	shift_x(t_map *map, int shift)
{
	 int i;
	 int j;

	 i = -1;
	 while (++i < (int)map->row)
	 {
	 	j = -1;
	 	while (++j < (int)map->col)
	 		map->dots[i][j].x += shift;
	 }
}

void	shift_y(t_map *map, int shift)
{
	int i;
	int j;

	i = -1;
	while (++i < (int)map->row)
	{
		j = -1;
		while (++j < (int)map->col)
			map->dots[i][j].y += shift;
	}
}

void rotate_z(t_map *map, double angle)
{
	int i;
	int j;

	i = -1;
	while (++i < (int)map->row)
	{
		j = -1;
		while (++j < (int)map->col)
		{
			map->dots[i][j].x = (int)  (((map->dots[i][j].x - map->x0) * cos(angle) +
										   (map->dots[i][j].y - map->y0) * sin(angle))) + map->x0;
			map->dots[i][j].y = (int) (((map->dots[i][j].y - map->y0) * cos(angle) -
										  (map->dots[i][j].x - map->x0) * sin(angle)) + map->y0);
		}
	}
}

void rotate_x(t_map *map, double angle)
{
	int i;
	int j;

	i = -1;
	while (++i < (int) map->row)
	{
		j = -1;
		while (++j < (int) map->col)
		{
			map->dots[i][j].y = (int) ((map->dots[i][j].y - map->y0) * cos(angle) +
									   (map->dots[i][j].z - map->z0) * sin(angle)) + map->y0;
			map->dots[i][j].z = (int) ((map->dots[i][j].z - map->z0) * cos(angle) -
									   (map->dots[i][j].y - map->y0) * sin(angle)) + map->z0;
		}
	}
}
void rotate_y(t_map *map, double angle)
{
	int i;
	int j;

	i = -1;
	while (++i < (int) map->row)
	{
		j = -1;
		while (++j < (int) map->col)
		{
			map->dots[i][j].x = (int) ((map->dots[i][j].x - map->x0) * cos(angle) +
											(map->dots[i][j].z - map->z0) * sin(angle))  + map->x0;
			map->dots[i][j].z = (int) ((map->dots[i][j].z - map->z0) * cos(angle) -
											(map->dots[i][j].x - map->x0) * sin(angle)) + map->z0;
		}
	}
}
