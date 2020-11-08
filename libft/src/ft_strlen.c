/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:54:23 by rpoetess          #+#    #+#             */
/*   Updated: 2019/01/30 15:54:27 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlen(const char *string)
{
	size_t i;

	i = 0;
	while ((string[i]) != '\0')
		i++;
	return (i);
}

size_t	ft_len(void **s)
{
	int n;

	n = 0;
	while (*s++)
		n++;
	return (n);
}
