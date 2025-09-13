/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <rtorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:59:25 by rtorres           #+#    #+#             */
/*   Updated: 2024/07/09 15:27:39 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft.h"

long		ft_abs(long nbr);
int			ft_putaddress(void *format);
void		ft_putbase_fd(int nbr, const char *base, int fd);
int			ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
int			ft_puthexa(unsigned long nbr, char format);
int			ft_putnbr(int nbr);
void		ft_putnbr_fd(int nbr, int fd);
int			ft_putstr(char const *str);
int			ft_putunsigned(unsigned long nbr);
char		*ft_strchr(const char *str, int c);
size_t		ft_strlen(const char *str);
int			ft_printf(const char *str, ...);

#endif
