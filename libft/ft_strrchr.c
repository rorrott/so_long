/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:27:41 by rtorres           #+#    #+#             */
/*   Updated: 2024/05/20 17:01:00 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last_occurrence;

	last_occurrence = 0;
	while (*str != '\0')
	{
		if (*str == (char)c)
			last_occurrence = str;
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return ((char *)last_occurrence);
}
