/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:13:46 by rtorres           #+#    #+#             */
/*   Updated: 2024/06/03 12:15:19 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned long nbr, char format)
{
	char			*base;
	unsigned int	num;
	int				i;
	unsigned int	base_len;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	num = (unsigned int)nbr;
	base_len = ft_strlen(base);
	if (num >= base_len)
		i += ft_puthexa(num / base_len, format);
	i += ft_putchar(base[num % base_len]);
	return (i);
}
