/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <rtorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:07:46 by rtorres           #+#    #+#             */
/*   Updated: 2024/08/06 17:09:51 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	if (game->map[new_y][new_x] == EXIT && game->collectibles_left == 0)
	{
		ft_printf(GREEN "Level complete. YOU WIN!\n" RESET);
		close_game(game);
	}
	else if (game->map[new_y][new_x] == WALL)
		return ;
	else if (game->map[new_y][new_x] == COLLECTIBLES)
		collect_item(game, new_x, new_y);
	game->map[game->player_y][game->player_x] = FLOOR;
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[game->exit_y][game->exit_x] = EXIT;
	game->map[game->player_y][game->player_x] = PLAYER;
	game->step_count++;
	ft_printf(CYAN "Steps: %d\n" RESET, game->step_count);
	draw_maps(game, &game->img);
}

void	collect_item(t_game *game, int x, int y)
{
	if (game->map[y][x] == COLLECTIBLES)
	{
		game->map[y][x] = FLOOR;
		game->collectibles_left--;
	}
}

int	keyboard(int keyb, t_game *game)
{
	if (keyb == KEY_W)
		move_player(game, game->player_x, game->player_y - 1);
	else if (keyb == KEY_A)
		move_player(game, game->player_x - 1, game->player_y);
	else if (keyb == KEY_S)
		move_player(game, game->player_x, game->player_y + 1);
	else if (keyb == KEY_D)
		move_player(game, game->player_x + 1, game->player_y);
	if (keyb == XK_Escape)
		close_game(game);
	return (0);
}

void	draw_maps(t_game *game, t_img *img)
{
	draw_map(game, img);
	draw_second_map(game, img);
	draw_map_exit(game, img);
}

int	check_open_file(t_game *game, char *file)
{
	int	map_file;

	map_file = open(file, __O_DIRECTORY);
	if (map_file != -1)
	{
		close(map_file);
		print_error(game, "Error!\nDirectory or map does not exist.\n");
	}
	map_file = open(file, O_RDONLY);
	if (map_file == -1)
	{
		close(map_file);
		print_error(game, "Error\nMap does not exist.\n");
	}
	return (map_file);
}
