/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:02:59 by rtorres           #+#    #+#             */
/*   Updated: 2024/05/21 17:44:59 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t				i;
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	if (src_ptr < dest_ptr)
	{
		i = num;
		while (i > 0)
		{
			dest_ptr[i - 1] = src_ptr[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < num)
		{
			dest_ptr[i] = src_ptr[i];
			i++;
		}
	}
	return (dest);
}
