/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:37:33 by rtorres           #+#    #+#             */
/*   Updated: 2024/05/24 14:52:06 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;
	size_t	d;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (!dest && size == 0)
		return (src_len);
	d = dest_len;
	if (size <= d)
		return (size + src_len);
	i = 0;
	while (src[i] && dest_len + 1 < size)
	{
		dest[dest_len] = src[i];
		i++;
		dest_len++;
	}
	dest[dest_len] = '\0';
	return (d + src_len);
}
