/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:21:02 by rtorres           #+#    #+#             */
/*   Updated: 2024/05/21 17:47:03 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)ptr;
	while (i < num)
	{
		str[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}
