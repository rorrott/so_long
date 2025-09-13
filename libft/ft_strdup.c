/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:30:37 by rtorres           #+#    #+#             */
/*   Updated: 2024/05/27 17:11:49 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	size;
	char	*ptr;

	size = ft_strlen(str);
	ptr = (char *)malloc(size * sizeof(char) + 1);
	if (ptr == NULL)
		return (0);
	ft_memcpy(ptr, str, size);
	ptr[size] = '\0';
	return (ptr);
}
