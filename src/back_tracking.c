/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <rtorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:20:53 by rtorres           #+#    #+#             */
/*   Updated: 2024/08/06 13:53:14 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	seed_fill(t_game *game, char **map, int x, int y)
{
	if (map[y][x] == WALL)
		return ;
	if (map[y][x] == EXIT)
		game->flood_exit++;
	else if (map[y][x] == COLLECTIBLES)
		game->flood_collect++;
	map[y][x] = WALL;
	seed_fill(game, map, x + 1, y);
	seed_fill(game, map, x - 1, y);
	seed_fill(game, map, x, y + 1);
	seed_fill(game, map, x, y - 1);
}

char	**ft_copy(char **copy, int height)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * (height + 1));
	if (!new)
		return (NULL);
	while (i < height)
	{
		new[i] = ft_strdup(copy[i]);
		if (!new[i])
			free_map_copy(new, height);
		i++;
	}
	new[i] = NULL;
	return (new);
}

void	free_map_copy(char **copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(copy[i]);
		i++;
	}
	free(copy);
}

void	ft_player(t_game *game)
{
	char	**copy_map;
	int		i;
	size_t	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < ft_strlen(game->map[i]))
		{
			if (game->map[i][j] == PLAYER)
			{
				game->player_y = i;
				game->player_x = j;
				break ;
			}
			j++;
		}
		i++;
	}
	copy_map = ft_copy(game->map, game->height);
	seed_fill(game, copy_map, game->player_x, game->player_y);
	free_map_copy(copy_map, game->height);
}

void	see_fill_result(t_game *game)
{
	if (game->collectibles == game->flood_collect
		&& game->exit == game->flood_exit)
		ft_message("All collectibles were collected");
	else
		print_error(game, "Error\nNot all collectibles were collected.\n");
}
