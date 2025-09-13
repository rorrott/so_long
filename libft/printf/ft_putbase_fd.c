/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:07:14 by rtorres           #+#    #+#             */
/*   Updated: 2024/06/03 12:17:18 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putbase_fd(int nbr, const char *base, int fd)
{
	int		base_len;
	long	n;
	char	c;

	base_len = ft_strlen(base);
	n = nbr;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= base_len)
		ft_putbase_fd(n / base_len, base, fd);
	c = base[n % base_len];
	write(fd, &c, 1);
}
