/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <rtorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:28:47 by rtorres           #+#    #+#             */
/*   Updated: 2024/08/06 14:29:33 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	init_map(t_game *game, char *file)
{
	int		map_file;
	char	*line_map;
	char	*line_tmp;
	int		empty;

	map_file = check_open_file(game, file);
	line_map = ft_strdup("");
	line_tmp = get_next_line(map_file);
	empty = 0;
	while (line_tmp != NULL)
	{
		if (line_tmp[0] == '\n')
			empty = 1;
		line_map = ft_freejoin(line_map, line_tmp, ft_strlen(line_map), \
		ft_strlen(line_tmp));
		free(line_tmp);
		line_tmp = get_next_line(map_file);
	}
	game->map = ft_split(line_map, '\n');
	game->height = check_map_height(game->map);
	if (empty)
		(free(line_map), print_error(game, "Empty line"));
	return (free(line_map), is_empty(game), close(map_file), 0);
}

int	check_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	game_init(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->pixel = PIXEL;
}

void	init_check_map(t_game *game, char *path)
{
	game_init(game);
	init_map(game, path);
	check_extension_file(game, path);
	check_map_valid(game);
	check_game(game);
	check_map(game);
	check_wall_border(game);
	ft_player(game);
	see_fill_result(game);
	game->collectibles_left = game->collectibles;
}

void	print_map(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map[i])
		print_error(game, "Error\nMap is not initialized.\n");
	ft_printf(GREEN "Map is valid\n" RESET);
	ft_printf("Map:\n");
	while (game->map[i])
		ft_printf(GREEN "%s\n" RESET, game->map[i++]);
}
