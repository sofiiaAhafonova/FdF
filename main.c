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

void print_map(t_map *map)
{
	t_dot cur;
	unsigned int k;

	if (!map)
		return;
	k = 0;
	// ft_putnbr((int)map->col);
	while (k < map->row * map->col)
	{
		cur = map->dots[k];
		if (cur.z < 10 && cur.x > 0)
			ft_putchar(' ');
		ft_putnbr(cur.z);
		ft_putchar(' ');
		if (cur.x == (int)map->col - 1)
			ft_putchar('\n');
		k++;
	}
}

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

void line(t_dot A, t_dot B, void *ret, void *window)
{
	int err;
	int e2;
	t_dot D;
	t_dot S;

	D.x = abs(B.x - A.x);
	D.y = abs(B.y - A.y);
	S.x = A.x < B.x ? 1 : -1;
	S.y = A.y < B.y ? 1 : -1;
	err = (D.x > D.y ? D.x : -D.y) / 2;
	while(1)
	{
		mlx_pixel_put(ret, window, A.x, A.y, 100700100);
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
}

t_map *zoom_map(t_map *map)
{
	int k;
	t_dot cur;

	k = -1;
	while (++k < (int)(map->col * map->row))
	{
		cur = map->dots[k];
		cur.x *= map->zoom;
		cur.y *= map->zoom;
		cur.z *= map->zoom;
		map->dots[k] = cur;
	}
	return (map);
}

int put_image(void *mlx_ptr, void *window, t_map *map)
{
	int k;
	t_dot cur;

	if (!mlx_ptr || !window)
		return (1);
	map = zoom_map(map);
	k = -1;
	while (++k < (int)(map->col * map->row))
	{
		cur = map->dots[k];
		mlx_pixel_put(mlx_ptr, window, cur.x, cur.y, 100700100);
		if (k < (int)(map->col * (map->row - 1)))
			line(cur, map->dots[k + map->col], mlx_ptr, window);
		if (k < (int)((map->col - 1) * map->row) && map->dots[k + 1].x)
			line(cur, map->dots[k + 1], mlx_ptr, window);
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
	print_map(map);
	void *mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (print_error("mlx init error"));
	void *window = mlx_new_window(mlx_ptr, 2000, 1200, "test");
	if (!window)
		return (print_error("window creation error"));
	map->mlx_ptr = mlx_ptr;
	map->window = window;
	map->zoom = start_zoom(map);
	put_image(mlx_ptr, window, map);
	mlx_key_hook(window, on_key_press, map);
	mlx_loop(mlx_ptr);
	return (0);
}