/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <sahafono@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 21:23:00 by sahafono          #+#    #+#             */
/*   Updated: 2018/05/01 13:55:14 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "fdf.h"

int			print_error(char *error)
{
	ft_putendl(error);
	return (0);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_list	*list;
	t_map	*map;

	if (argc != 2)
		return (print_error("usage: ./fdf fdf_file"));
	fd = open(argv[1], O_RDONLY);
	list = NULL;
	if (fd < 0)
		return (print_error("map reading error"));
	map = read_map(fd, &list);
	if (!map)
		return (print_error("map parsing error"));
	initialize_map(map);
	rotate(map);
	put_image(map);
	mlx_hook(map->window, 17, 1L << 17, &close_window, map);
	mlx_hook(map->window, 2, 5, on_key_press, map);
	mlx_loop(map->mlx_ptr);
	return (0);
}
