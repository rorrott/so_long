/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <rtorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 11:49:57 by rtorres           #+#    #+#             */
/*   Updated: 2024/08/01 11:51:25 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i] || buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	line = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	line[j] = '\0';
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		line = malloc(i + 2 * sizeof(char));
	else
		line = malloc(i + 1 * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_initres(char *res)
{
	res = malloc(sizeof(char));
	if (!res)
		return (NULL);
	res[0] = '\0';
	return (res);
}

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;
	int		size;

	if (!res)
		res = ft_initres(res);
	size = ft_strlen(res);
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (free(res), NULL);
	buffer[0] = '\0';
	byte_read = 1;
	while (!ft_strchr(buffer, '\n') && byte_read != 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(buffer), free(res), NULL);
		buffer[byte_read] = '\0';
		if (byte_read == 0)
			break ;
		res = ft_freejoin(res, buffer, size, byte_read);
		size += byte_read;
	}
	return (free(buffer), res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer || buffer[0] == '\0')
		return (free(buffer), buffer = NULL, NULL);
	line = ft_line(buffer);
	if (!line || line[0] == '\0')
		return (free(buffer), free(line), NULL);
	buffer = ft_next(buffer);
	if (buffer && buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}
