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
		map->dots[k].x = (int) (map->dots[k].x * cos(angle) + map->dots[k].y * sin(angle));
		map->dots[k].y = (int) (map->dots[k].y * cos(angle) - map->dots[k].x * sin(angle));
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
		map->dots[k].y = (int) (map->dots[k].y * cos(angle) + map->dots[k].z * sin(angle));
		map->dots[k].z = (int) (map->dots[k].z * cos(angle) - map->dots[k].y * sin(angle));
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
		map->dots[k].x = (int) (map->dots[k].x * cos(angle) + map->dots[k].z * sin(angle));
		map->dots[k].z = (int) (map->dots[k].z * cos(angle) - map->dots[k].x * sin(angle));
		k++;
	}
}
