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

void print_map(t_map *map, int **arr)
{
    for (int i = 0; i < (int)map->row; i++)
    {
        ft_putendl("");
        for (int j = 0; j < (int)map->col; j++)
        {
            if (arr[i][j] < 10 && j > 0)
                ft_putchar(' ');
            ft_putnbr(arr[i][j]);
            ft_putchar(' ');
        }
    }
}

int		print_error(char *error)
{
	ft_putendl(error);
	return (0);
}

int		start_zoom(t_map *map)
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

int		put_image(void *mlx_ptr, void *window, int **arr, t_map *map)
{
	int		zoom;
	
	if (!arr || !*arr || !mlx_ptr || !window)
		return (1);
	zoom = start_zoom(map);
	for (int i = 0; i < (int)map->row; i++)
        for (int j = 0; j < (int)map->col; j++)
            mlx_pixel_put(mlx_ptr, window, zoom * j + 500, zoom * i + 100,  111209533);
	return (0);
}


int 	main(int argc, char **argv)
{
	int		fd;
    t_list  *list;
	t_map *map;

	if (argc != 2)
		return(print_error("usage: ./fdf fdf_file"));
	fd = open(argv[1], O_RDONLY);
	list = NULL;
	if (fd < 0)
		return (print_error("map reading error"));
    map = read_map(fd, &list);
	if (!map)
		return (print_error("map parsing error"));
    int **arr = list_to_arr(map);
    print_map(map, arr);
	void *mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (print_error("mlx init error"));
	void *window = mlx_new_window(mlx_ptr, 2000, 1200, "test");
	if (!window)
		return (print_error("window creation error"));
	put_image(mlx_ptr, window, arr, map);
	mlx_key_hook(window, on_key_press, (void*)0);
	mlx_loop(mlx_ptr);
	return (0);
}