/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <rtorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:46:12 by rtorres           #+#    #+#             */
/*   Updated: 2024/08/06 15:29:53 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	check_map(t_game *game)
{
	int	i;
	int	width;
	int	current_width;

	i = 1;
	width = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		current_width = ft_strlen(game->map[i]);
		if (current_width != width)
			print_error(game, "Error: Map should be rectangular.");
		i++;
	}
}

void	check_wall_border(t_game *game)
{
	int	i;
	int	width;
	int	height;

	i = 0;
	width = ft_strlen(game->map[0]);
	height = game->height;
	game->width = width;
	if (!game->map[i] || game->height == 1)
		print_error(game, "Error\nMap must be initialized.\n");
	while (i < width)
	{
		if (game->map[0][i] != WALL || (game->map[height - 1][i] != WALL))
			print_error(game, "Error\nMap is not enclosed by walls.\n");
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (game->map[i][0] != WALL || (game->map[i][width - 1] != WALL))
			print_error(game, "Error\nMap is not enclosed by wall borders.\n");
		i++;
	}
}

void	check_map_valid(t_game *game)
{
	int		i;
	int		j;
	char	*map_s;

	map_s = "10PECX";
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (!ft_strchr(map_s, game->map[i][j]))
				print_error(game, "Error\nMap only accepts (10PEC).\n");
			j++;
		}
		i++;
	}
}

void	check_game_utils(t_game *game, int exit, int collectibles, int spawn)
{
	if (exit != 1)
		print_error(game, "Error\nIt must have at least one exit.\n");
	if (spawn != 1)
		print_error(game, "Error\nIt must have exactly one starting point.\n");
	if (collectibles < 1)
		print_error(game, "Error\nIt must have at least one collectibles.\n");
}

void	check_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == COLLECTIBLES)
				game->collectibles++;
			else if (game->map[i][j] == EXIT)
				game->exit++;
			else if (game->map[i][j] == PLAYER)
				game->spawn++;
		}
		i++;
	}
	check_game_utils(game, game->exit, game->collectibles, game->spawn);
}
