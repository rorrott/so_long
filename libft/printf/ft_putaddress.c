/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:58:31 by rtorres           #+#    #+#             */
/*   Updated: 2024/06/03 15:40:25 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printadd(unsigned long nbr, const char *base)
{
	int	len;
	int	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (nbr >= (unsigned long)base_len)
		len += ft_printadd(nbr / base_len, base);
	len += ft_putchar(base[nbr % base_len]);
	return (len);
}

int	ft_putaddress(void *format)
{
	unsigned long	nbr;
	const char		*base;
	int				len;

	nbr = (unsigned long)format;
	base = "0123456789abcdef";
	len = ft_putstr("0x");
	len += ft_printadd(nbr, base);
	return (len);
}
