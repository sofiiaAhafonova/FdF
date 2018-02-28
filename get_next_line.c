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

#include "get_next_line.h"

int						find_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == '\n')
			return (i);
	return (-1);
}

char					*read_file(t_storage *storage, int fd)
{
	char				*buf;
	int					res;

	buf = ft_strnew(BUFF_SIZE + 1);
	res = -1;
	if ((res = read(fd, buf, BUFF_SIZE)) == -1)
	{
		ft_strdel(&buf);
		return (NULL);
	}
	if (res == 0)
	{
		storage->end_reading = 1;
		ft_strdel(&buf);
		return (NULL);
	}
	return (buf);
}

int						fill_line(t_storage *storage, char **line, int i)
{
	char				*tmp;
	int					j;
	int					len;

	if (storage->end_reading && storage->str[0] == '\0')
		return (0);
	if (i == -1)
		len = ft_strlen(storage->str) + 1;
	else
		len = i - 1;
	if (!(*line = ft_strnew(len)))
		return (-1);
	j = -1;
	while (++j < len)
		(*line)[j] = storage->str[j];
	if (i == -1)
		i = len - 1;
	tmp = ft_strdup(storage->str + i);
	ft_strdel(&storage->str);
	storage->str = tmp;
	return (1);
}

char					*ft_strjoin_mod(char *s1, char *s2)
{
	char				*tmp;

	tmp = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (tmp);
}

int						get_next_line(const int fd, char **line)
{
	char				*buf;
	static t_storage	storage[FD_MAX];
	int					i;

	if (fd < 0 || fd >= FD_MAX || BUFF_SIZE < 1 || !line)
		return (-1);
	buf = NULL;
	if (!(buf = read_file(&(storage[fd]), fd)) && !storage[fd].end_reading)
		return (-1);
	if (!storage[fd].str)
		storage[fd].str = ft_strnew(0);
	if (buf)
		storage[fd].str = ft_strjoin_mod(storage[fd].str, buf);
	if ((i = find_new_line(storage[fd].str)) == -1)
	{
		if (storage[fd].end_reading)
			return (fill_line(&(storage[fd]), line, i));
		return (get_next_line(fd, line));
	}
	return (fill_line(&(storage[fd]), line, i));
}
