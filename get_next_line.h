/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:00:46 by sahafono          #+#    #+#             */
/*   Updated: 2018/02/07 20:58:21 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# define BUFF_SIZE 100000
# define FD_MAX 1024

typedef struct	s_storage
{
	size_t		end_reading;
	char		*str;
}				t_storage;
int				get_next_line(const int fd, char **line);

#endif
