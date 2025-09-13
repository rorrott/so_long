/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:20:10 by rtorres           #+#    #+#             */
/*   Updated: 2024/06/03 12:14:16 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_number_len(long nbr)
{
	int	i;

	if (nbr < 0)
	{
		nbr = ft_abs(nbr);
		i = 1;
	}
	else
		i = 0;
	while (nbr >= 10)
	{
		nbr /= 10;
		i++;
	}
	return (i + 1);
}

int	ft_putnbr(int nbr)
{
	int	nbr_len;

	nbr_len = ft_number_len(nbr);
	ft_putnbr_fd(nbr, 1);
	return (nbr_len);
}
