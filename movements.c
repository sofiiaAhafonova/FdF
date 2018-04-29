#include "fdf.h"
#include <math.h>


double *trigonometric_func(t_map *map){
	double *trigonometric_func;

	trigonometric_func = ft_memalloc(sizeof(double) * 6);
	trigonometric_func[0] = sin(map->wx);
	trigonometric_func[1] = cos(map->wx);
	trigonometric_func[2] = sin(map->wy);
	trigonometric_func[3] = cos(map->wy);
	trigonometric_func[4] = sin(map->wz);
	trigonometric_func[5] = cos(map->wz);
	return (trigonometric_func);
}

void rotate(t_map *map)
{
	int i;
	int j;
	int x_coord;
	double *ar;

	i = -1;
	ar = trigonometric_func(map);
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			map->offset[i][j].y = (int)(map->base[i][j].y * ar[1] - map->base[i][j].z * ar[0]);
			map->offset[i][j].z = (int)(map->base[i][j].z * ar[1] + map->base[i][j].y * ar[0]);
			map->offset[i][j].x = (int)(map->base[i][j].x * ar[3] + map->base[i][j].z * ar[2]);
			map->offset[i][j].z = (int)(map->offset[i][j].z * ar[3] - map->offset[i][j].x * ar[2]);
			x_coord = map->offset[i][j].x;
			map->offset[i][j].x = (int)(x_coord * ar[5] - map->offset[i][j].y * ar[4]) + map->offset_x;
			map->offset[i][j].y = (int)(map->offset[i][j].y * ar[5] + x_coord * ar[4]) + map->offset_y;
			int color =  map->base[i][j].z / map->zoom;
			map->offset[i][j].color.rgb = color;
		}
	}
	free(ar);
}
