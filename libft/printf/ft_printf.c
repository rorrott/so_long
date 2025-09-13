/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:35:56 by rtorres           #+#    #+#             */
/*   Updated: 2024/06/03 15:59:10 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char format)
{
	void	*ptr;

	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (format == 'X' || format == 'x')
		return (ft_puthexa(va_arg(args, unsigned int), format));
	else if (format == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr)
			return (ft_putaddress(ptr));
		return (ft_putstr("(nil)"));
	}
	else if (format == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			len += ft_format(args, str[i + 1]);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
