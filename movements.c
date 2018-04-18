#include "fdf.h"
#include <math.h>
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

void rotate_z(t_map *map, double angle) {
	unsigned int k;
	unsigned int len;

	k = 0;
	len = map->col * map->row;
	while (k < len)
	{

		map->dots[k].x = (int)  round(((map->dots[k].x - map->x0) * cos(angle) +
								(map->dots[k].y - map->y0) * sin(angle))) + map->x0;
		map->dots[k].y = (int) round(((map->dots[k].y - map->y0) * cos(angle) -
								(map->dots[k].x - map->x0) * sin(angle)) + map->y0);
		k++;
	}
}

void rotate_x(t_map *map, double angle) {
	unsigned int k;
	unsigned int len;

	k = 0;
	len = map->col * map->row;
	while (k < len)
	{
		map->dots[k].y = (int) ((map->dots[k].y - map->y0) * cos(angle) +
								(map->dots[k].z - map->z0) * sin(angle)) + map->y0;
		map->dots[k].z = (int) ((map->dots[k].z - map->z0) * cos(angle) -
								(map->dots[k].y - map->y0) * sin(angle)) + map->z0;
		k++;
	}
}

void rotate_y(t_map *map, double angle) {
	unsigned int k;
	unsigned int len;

	k = 0;
	len = map->col * map->row;
	while (k < len)
	{
		map->dots[k].x = (int) ((map->dots[k].x - map->x0) * cos(angle) +
								(map->dots[k].z - map->z0) * sin(angle))  + map->x0;
		map->dots[k].z = (int) ((map->dots[k].z - map->z0) * cos(angle) -
								(map->dots[k].x - map->x0) * sin(angle)) + map->z0;
		k++;
	}
}
