/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_buff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <rpoetess@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:57:25 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/12 18:11:15 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*t_buff_init(t_buff *b, size_t size)
{
	b->size = size;
	b->len = 0;
	b->data = malloc(sizeof(char) * (size + 1));
	return (b->data);
}

size_t	t_buff_extend(t_buff *b)
{
	size_t size_old;

	size_old = b->size;
	b->size *= 2;
	if (!(b->data = ft_realloc(b->data, size_old, b->size + 1)))
		return (0);
	return (b->size);
}

int		t_buff_append(t_buff *b, void *data, size_t len)
{
	while (b->len + len > b->size)
		if (!t_buff_extend(b))
			return (0);
	ft_memcpy(b->data + b->len, data, len);
	b->len += len;
	return (1);
}
