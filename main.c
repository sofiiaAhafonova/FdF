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


int 	main(int argc, char **argv)
{
	char	*str;
	int		fd;

	if (argc != 2)
		ft_putstr("usage: ./fdf fdf_file");
	else
	{
		fd = open(argv[1], O_RDONLY);
		while (get_next_line(fd, &str) == 1)
		{
			ft_putstr(str);
			ft_putchar('\n');
			ft_strdel(&str);
		}
	}
	return (0);
}