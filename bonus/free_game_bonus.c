/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <rtorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:34:09 by rtorres           #+#    #+#             */
/*   Updated: 2024/08/06 14:29:27 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		ft_free_split(game->map);
		game->map = NULL;
	}
}

void	print_error(t_game *game, const char *s)
{
	ft_printf(RED "%s\n" RESET, s);
	free_map(game);
	free_mlx_img(&game->img);
	close_game(game);
	exit(0);
}

void	ft_message(const char *s)
{
	ft_printf(GREEN "%s\n" RESET, s);
}

void	check_extension_file(t_game *game, char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 4 || !ft_strnstr(&file[len - 4], ".ber", 4))
		print_error(game, "Error\nWrong map extension. It must be .ber!\n");
}

void	is_empty(t_game *game)
{
	int	i;

	i = 0;
	if (game->map[i] == NULL)
		print_error(game, "Error\nMap is empty.\n");
}
