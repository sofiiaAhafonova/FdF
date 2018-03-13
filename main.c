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
}

int 	main(int argc, char **argv)
{
	char	*str;
	int		fd;

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
		void *ret;
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
		ft_putendl("\n10-70.fdf");
		int fd1 = open("test_maps/10-70.fdf", O_RDONLY);
		if (fd1 >= 0)
			read_map(fd1);
	}
	return (0);
}