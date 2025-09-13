/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:59:42 by rtorres           #+#    #+#             */
/*   Updated: 2024/05/21 17:49:51 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	const unsigned char	*p;
	size_t				i;

	p = (const unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		if (p[i] == (unsigned char)value)
			return ((void *)(p + i));
		i++;
	}
	return (0);
}
