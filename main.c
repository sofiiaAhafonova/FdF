/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <sahafono@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 21:23:00 by sahafono          #+#    #+#             */
/*   Updated: 2018/02/28 21:23:00 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"
#include "get_next_line.h"
#include "fdf.h"
#include <math.h>

int print_error(char *error)
{
	ft_putendl(error);
	return (0);
}

int start_zoom(t_map *map)
{
	if (map->row <= 10 && map->col <= 10)
		return (30);
	if (map->row <= 20 && map->col <= 20)
		return (25);
	if (map->row <= 30 && map->col <= 30)
		return (20);
	if (map->row <= 40 && map->col <= 40)
		return (15);
	if (map->row <= 60 && map->col <= 60)
		return (15);
	if (map->row <= 100 && map->col <= 100)
		return (10);
	return (5);
}

t_dot	module(t_dot A, t_dot B)
{
	t_dot D;

	D.x = abs(B.x - A.x);
	D.y = abs(B.y - A.y);
	return (D);
}

t_dot	direction(t_dot A, t_dot B)
{
	t_dot S;

	S.x = A.x < B.x ? 1 : -1;
	S.y = A.y < B.y ? 1 : -1;
	S.z = A.z < B.z ? 1 : -1;
	if (A.color.rgb == B.color.rgb)
		S.color = A.color;
	else {
		S.color.rgb = abs(A.color.rgb - B.color.rgb) / 2;
		S.color.rgb += A.color.rgb > B.color.rgb ? B.color.rgb : A.color.rgb;
	}
	return (S);
}

int medium_color(t_dot A, t_dot B, t_map *map)
{
	int base_color;
	t_color color;
	int shift;

	color = map->color;
	if (A.color.rgb > B.color.rgb)
		base_color = B.color.rgb;
	else
		base_color = A.color.rgb;
	if (base_color < 0 && map->color.green - 32 > 0)
		shift = -32;
	else if (base_color == 0)
		shift = 0;
	else if (base_color > 0 && base_color < 5 && map->color.green + 32 <= 256)
		shift = 32;
	else if (base_color >= 5 && base_color < 10  && map->color.green +  64 <= 256)
		shift = 64;
	else if (base_color >= 10 && base_color < 20 && map->color.green +  96 <= 256)
		shift = 96;
	else if (base_color >= 20 && base_color < 50)
		set_color(&color, 180, 180, 180);
	else if (base_color >= 50 && base_color < 70)
		set_color(&color, 200, 200,200);
	else if (base_color >= 70)
		set_color(&color, 220, 220, 220);
	else
		shift = 256 - map->color.green;
	set_color(&color, map->color.red, map->color.green + shift, map->color.blue);
	return (color.rgb);

}

int	line(t_dot A, t_dot B, t_map *map)
{
	int err;
	int e2;
	t_dot D;
	t_dot S;

	D = module(A, B);
	S = direction(A, B);
	err = (D.x > D.y ? D.x : -D.y) / 2;
	while(1)
	{
		mlx_pixel_put(map->mlx_ptr, map->window, A.x, A.y, medium_color(A, B, map));
		if (A.x == B.x && A.y == B.y)
			break;
		e2 = err;
		if (e2 > -D.x)
		{
			err -= D.y;
			A.x += S.x;
		}
		if (e2 < D.y)
		{
			err += D.x;
			A.y += S.y;
		}
	}
	return medium_color(A, B, map);
}

void zoom_map(t_map *map)
{
	int i;
	int j;
	t_dot cur;

	if (!map || map->zoom < 1)
		return ;
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			cur = map->base[i][j];
			cur.x = j *map->zoom - (map->col * map->zoom)/2 ;
			cur.y = i * map->zoom - (map->row * map->zoom)/2 ;
			cur.z *= map->zoom;
			map->base[i][j] = cur;
		}
	}
}

int put_image(t_map *map)
{
	int i;
	int j;
	t_dot cur;

	if (!map || !map->mlx_ptr || !map->window)
		return (1);
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			cur = map->offset[i][j];
			if (j != map->col - 1)
				cur.color.rgb = line(cur, map->offset[i][j + 1], map);
			if (i != map->row - 1)
				cur.color.rgb = line(cur, map->offset[i + 1][j], map);
			mlx_pixel_put(map->mlx_ptr, map->window, cur.x, cur.y, cur.color.rgb);
		}
	}
	return (0);
}

int main(int argc, char **argv)
{
	int fd;
	t_list *list;
	t_map *map;

	if (argc != 2)
		return (print_error("usage: ./fdf fdf_file"));
	fd = open(argv[1], O_RDONLY);
	list = NULL;
	if (fd < 0)
		return (print_error("map reading error"));
	map = read_map(fd, &list);
	if (!map)
		return (print_error("map parsing error"));
	void *mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (print_error("mlx init error"));
	void *window = mlx_new_window(mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "test");
	if (!window)
		return (print_error("window creation error"));
	map->mlx_ptr = mlx_ptr;
	map->window = window;
	map->zoom = start_zoom(map);
	zoom_map(map);
    map->offset = (t_dot**)malloc(sizeof(t_dot *) * map->row);
    int i = -1;
    while (++i < map->row)
        map->offset[i] = malloc(sizeof(t_dot)*map->col);
	map->offset_x = SCREEN_WIDTH / 2;
	map->offset_y =  SCREEN_HEIGHT / 2;
	map->wz = 0 *  DEEGRE;
	map->wy = 0 *  DEEGRE;
	map->wx = 0 *  DEEGRE;
	rotate(map);
	put_image(map);
	mlx_hook(map->window, 17, 1L << 17,&close_window, map);
	mlx_hook(map->window,2, 5, on_key_press, map);
	mlx_loop(mlx_ptr);
	return (0);
}