/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:28:28 by rtorres           #+#    #+#             */
/*   Updated: 2024/05/21 17:45:37 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t				i;
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	i = 0;
	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	while (i < size)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}
