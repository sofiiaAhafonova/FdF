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

int 	exit_key(int key, void *param)
{
	if (param)
		;
	if (key == 65307)
		exit(0);
    return (0);
}


void print_map(t_map *map, int **arr)
{
    for (int i = 0; i < map->row; i++)
    {
        ft_putendl("");
        for (int j = 0; j < map->col; j++)
        {
            if (arr[i][j] < 10 && j > 0       )
                ft_putchar(' ');
            ft_putnbr(arr[i][j]);
            ft_putchar(' ');
        }
    }
}

int 	main(int argc, char **argv)
{
	char	*str;
	int		fd;
    t_list  *list;

	if (argc != 2)
		ft_putstr("usage: ./fdf fdf_file");
	else
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &str) > 0)
		{
			ft_putstr(str);
			ft_putchar('\n');
			ft_strdel(&str);
		}
        close(fd);
		void *ret;
		if (!(ret = mlx_init()))
		{
			ft_putstr("Connection failed\n");
			return (1);
		}
		void *window = mlx_new_window(ret, 1000, 1000, "test");
		if (!window)
		{
			ft_putstr("Window creation failed");
			return (1);
		}
		mlx_key_hook(window, exit_key, (void*)0);
		mlx_loop(ret);
        fd = open(argv[1], O_RDONLY);
        ft_putendl("");
		ft_putendl(argv[1]);
        list = NULL;
        t_map *map;
		if (fd < 0)
            return (1);
        map = read_map(fd, &list);
        int **arr;
        arr = list_to_arr(map);
        print_map(map, arr);
	}
	return (0);
}