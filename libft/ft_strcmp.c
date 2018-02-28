/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:36:59 by sahafono          #+#    #+#             */
/*   Updated: 2017/11/13 13:37:02 by sahafono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char *a;
	const unsigned char *b;

	a = (const unsigned char*)s1;
	b = (const unsigned char*)s2;
	while (*a && *b && *a == *b)
	{
		a++;
		b++;
	}
	return (*a - *b);
}
