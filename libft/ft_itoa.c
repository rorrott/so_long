/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:23:26 by rtorres           #+#    #+#             */
/*   Updated: 2024/05/23 18:20:44 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_len(int n)
{
	int	len;

	len = 0;
	if (n < 1)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nbr;
	int		is_negative;

	len = get_num_len(n);
	is_negative = (n < 0);
	nbr = n;
	if (is_negative)
		nbr = -nbr;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		str[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}
