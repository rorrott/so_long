/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <rtorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 11:33:51 by rtorres           #+#    #+#             */
/*   Updated: 2024/08/06 13:55:46 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	close_display(t_game *game)
{
	mlx_destroy_display(game->img.mlx_ptr);
	free(game->img.mlx_ptr);
	free_map(game);
	exit(0);
}

int	close_game(t_game *game)
{
	if (game->img.mlx_ptr != NULL)
		mlx_destroy_window(game->img.mlx_ptr, game->img.win_ptr);
	free_mlx_img(&game->img);
	if (game->img.win_ptr != NULL)
		close_display(game);
	free_map(game);
	return (0);
}

int	close_window(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	init_struct(t_game *game)
{
	game->img.mlx_ptr = mlx_init();
	game->img.win_ptr = mlx_new_window(game->img.mlx_ptr, game->width \
						* game->pixel, game->height * game->pixel, "so long");
	if (!game->img.win_ptr)
	{
		ft_printf(RED "Mlx failed to open");
		free_map(game);
		free_mlx_img(&game->img);
		return ;
	}
	initialize_img(&game->img, game);
	draw_maps(game, &game->img);
	game->step_count = 0;
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf(RED "Usage: %s <map_dir>/<map_file>\n" RESET, av[0]);
		return (0);
	}
	init_check_map(&game, av[1]);
	init_struct(&game);
	mlx_hook(game.img.win_ptr, KeyPress, KeyPressMask, keyboard, &game);
	mlx_hook(game.img.win_ptr, DestroyNotify, 0, &close_game, &game);
	mlx_loop(game.img.mlx_ptr);
	close_game(&game);
	free_map(&game);
}
