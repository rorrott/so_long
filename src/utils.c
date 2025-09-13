/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <rtorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:11:30 by rtorres           #+#    #+#             */
/*   Updated: 2024/08/06 17:09:10 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	initialize_img(t_img *img, t_game *game)
{
	img->wall_img = mlx_xpm_file_to_image(img->mlx_ptr, "images/bloque.xpm", \
		&game->pixel, &game->pixel);
	if (img->wall_img == NULL)
		print_error(game, "Error\nFailed to load wall img.\n");
	img->floor_img = mlx_xpm_file_to_image(img->mlx_ptr, "images/tree.xpm", \
		&game->pixel, &game->pixel);
	if (img->floor_img == NULL)
		print_error(game, "Error\nFailed to load floor img.\n");
	img->player_img = mlx_xpm_file_to_image(img->mlx_ptr, "images/player.xpm", \
		&game->pixel, &game->pixel);
	if (img->player_img == NULL)
		print_error(game, "Error\nFailed to load player img.\n");
	img->collectibles_img = mlx_xpm_file_to_image(img->mlx_ptr, \
		"images/point.xpm", &game->pixel, &game->pixel);
	if (img->collectibles_img == NULL)
		print_error(game, "Error\nFailed to load collectibles img.\n");
	img->exit_img = mlx_xpm_file_to_image(img->mlx_ptr, "images/exit.xpm", \
		&game->pixel, &game->pixel);
	if (img->exit_img == NULL)
		print_error(game, "Error\nFailed to load exit img.\n");
}

void	draw_map(t_game *game, t_img *img)
{
	int	pos[4];

	pos[2] = 0;
	while (pos[2] < game->height)
	{
		pos[3] = 0;
		while (pos[3] < game->width)
		{
			pos[0] = pos[3] * game->pixel;
			pos[1] = pos[2] * game->pixel;
			if (game->map[pos[2]][pos[3]] == WALL)
				mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, \
				img->wall_img, pos[0], pos[1]);
			else if (game->map[pos[2]][pos[3]] == FLOOR)
				mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, \
				img->floor_img, pos[0], pos[1]);
			pos[3]++;
		}
		pos[2]++;
	}
}

void	draw_second_map(t_game *game, t_img *img)
{
	int	pos[4];

	pos[2] = 0;
	while (pos[2] < game->height)
	{
		pos[3] = 0;
		while (pos[3] < game->width)
		{
			pos[0] = pos[3] * game->pixel;
			pos[1] = pos[2] * game->pixel;
			if (game->map[pos[2]][pos[3]] == PLAYER)
				mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, \
				img->player_img, pos[0], pos[1]);
			else if (game->map[pos[2]][pos[3]] == COLLECTIBLES)
				mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, \
				img->collectibles_img, pos[0], pos[1]);
			pos[3]++;
		}
		pos[2]++;
	}
}

void	draw_map_exit(t_game *game, t_img *img)
{
	int	pos[4];

	pos[2] = 0;
	while (pos[2] < game->height)
	{
		pos[3] = -1;
		while (++pos[3] < game->width)
		{
			pos[0] = pos[3] * game->pixel;
			pos[1] = pos[2] * game->pixel;
			if (game->map[pos[2]][pos[3]] == EXIT)
			{
				mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, \
					img->exit_img, pos[0], pos[1]);
				game->exit_x = pos[3];
				game->exit_y = pos[2];
			}
		}
		pos[2]++;
	}
}

void	free_mlx_img(t_img *img)
{
	destroy_img(img->mlx_ptr, (void **)&img->collectibles_img);
	destroy_img(img->mlx_ptr, (void **)&img->exit_img);
	destroy_img(img->mlx_ptr, (void **)&img->floor_img);
	destroy_img(img->mlx_ptr, (void **)&img->player_img);
	destroy_img(img->mlx_ptr, (void **)&img->wall_img);
}
