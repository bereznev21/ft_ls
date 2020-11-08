/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 17:29:08 by rpoetess          #+#    #+#             */
/*   Updated: 2019/01/30 17:29:10 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int	chunk_len(const char *s, char c)
{
	int n;

	n = 0;
	while (*s && *s != c)
	{
		n++;
		s++;
	}
	return (n);
}

static int	count_chunks(const char *s, char c)
{
	int n;

	n = 0;
	while (1)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			return (n);
		n++;
		s += chunk_len(s, c);
	}
}

char		**ft_strsplit_clear(char **p)
{
	int i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	char	**ptr;
	int		l;

	if (!(ret = malloc(sizeof(char *) * (count_chunks(s, c) + 1))))
		return (0);
	ptr = ret;
	while (1)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
		{
			*ptr = 0;
			return (ret);
		}
		l = chunk_len(s, c);
		if (!(*ptr = malloc(sizeof(char) * (l + 1))))
			return (ft_strsplit_clear(ret));
		(*ptr)[l] = 0;
		ft_strncpy(*ptr++, s, l);
		s += l;
	}
}
