/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:19:48 by sahafono          #+#    #+#             */
/*   Updated: 2017/11/26 16:19:49 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcnt(char const *s, char c)
{
	int count;
	int i;

	if (!s)
		return (0);
	count = 0;
	i = 0;
	if (s[i] != c)
	{
		i++;
		count++;
	}
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static int	ft_word_len(char const *str, int i, char c)
{
	int len;

	len = 0;
	while (str[i] != c && str[i])
	{
		len++;
		i++;
	}
	return (len);
}

static char	**ft_free_ar(char **list, int i)
{
	int k;

	k = 0;
	while (k < i)
	{
		ft_strdel(&list[k]);
		k++;
	}
	free(list);
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**list;
	int		i;
	int		j;
	int		shift;

	if (!s || !(list = (char**)malloc(sizeof(char *) * (ft_wordcnt(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			shift = 0;
			if (!(list[j] = (char *)malloc((ft_word_len(s, i, c) + 1))))
				return (ft_free_ar(list, j));
			while (s[i] != c && s[i])
				list[j][shift++] = s[i++];
			list[j++][shift] = '\0';
		}
	}
	list[j] = 0;
	return (list);
}
