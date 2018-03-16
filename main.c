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

//#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "mlx.h"
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
//		void *ret;
//		if (!(ret = mlx_init()))
//		{
//			ft_putstr("Connection failed\n");
//			return (1);
//		}
//		void *window = mlx_new_window(ret, 1000, 1000, "test");
//		if (!window)
//		{
//			ft_putstr("Window creation failed");
//			return (1);
//		}
//		void *image = mlx_new_image(ret, 100, 100);
//		if (!image)
//		{
//			ft_putstr("Image creation failed");
//			return (1);
//		}
	//	mlx_put_image_to_window(ret, window, image, 10, 10);
		//mlx_key_hook(window, exit_key, (void*)0);
		//mlx_loop(ret);
        fd = open(argv[1], O_RDONLY);
        ft_putendl("");
		ft_putendl(argv[1]);
        list = NULL;
        t_map *map;
		if (fd < 0)
            return (1);
        map = read_map(fd, &list);
        ft_putstr("000");
	}
	return (0);
}