/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:31:29 by rtorres           #+#    #+#             */
/*   Updated: 2024/06/03 13:32:01 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned long nbr)
{
	int		len;
	char	*base;

	len = 0;
	base = "0123456789";
	if (nbr > ft_strlen(base) - 1)
		len += ft_putunsigned(nbr / ft_strlen(base));
	len += ft_putchar(base[nbr % ft_strlen(base)]);
	return (len);
}
