/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:00:32 by sahafono          #+#    #+#             */
/*   Updated: 2018/02/10 12:55:26 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin_mod(char *s1, char *s2)
{
	char			*tmp;

	tmp = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (tmp);
}

char				*read_line(char *stor)
{
	char			*str;
	size_t			len;
	size_t			i;

	len = 0;
	while (stor[len] != '\n')
		++len;
	str = ft_strnew(len + 1);
	i = 0;
	while (i < len)
	{
		str[i] = stor[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char				*copy_end(char *tmp)
{
	char *str;

	str = ft_strdup(ft_strchr(tmp, '\n') + 1);
	free(tmp);
	return (str);
}

int					get_next_line(const int fd, char **line)
{
	char			*buf;
	static char		*stor[FD_MAX];
	int				res;

	if (fd < 0 || fd >= FD_MAX || BUFF_SIZE < 1 || !line)
		return (-1);
	buf = ft_strnew(BUFF_SIZE);
	if ((res = read(fd, buf, BUFF_SIZE)) == -1)
	{
		free(buf);
		return (-1);
	}
	stor[fd] = !stor[fd] ? ft_strnew(0) : stor[fd];
	stor[fd] = ft_strjoin_mod(stor[fd], buf);
	if (!ft_strlen(stor[fd]))
		return (0);
	if (ft_strchr(stor[fd], '\n') && (*line = read_line(stor[fd])))
		stor[fd] = copy_end(stor[fd]);
	else if (!res && ft_strlen(stor[fd]) && (*line = ft_strdup(stor[fd])))
		ft_strdel(&stor[fd]);
	else
		return (get_next_line(fd, line));
	return (1);
}