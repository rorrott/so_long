/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtorres <rtorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 18:01:52 by rtorres           #+#    #+#             */
/*   Updated: 2024/08/08 10:31:51 by rtorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/gnl/get_next_line.h"   
# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# define WALL '1'
# define FLOOR '0'
# define COLLECTIBLES 'C'
# define EXIT 'E'
# define PLAYER 'P'

# define PIXEL 50

# define GREEN "\033[0;32m"
# define RED "\033[1;31m"
# define GREY "\033[0;90m"
# define CYAN "\033[1;96m"
# define RESET "\033[0m"
# define YELLOW "\033[0;33m"
# define PURPLE "\033[0;35m"

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define ESC 65307
# define ESC2 33

typedef struct s_img
{
	void	*img_ptr;
	void	*player_img;
	void	*collectibles_img;
	void	*exit_img;
	void	*floor_img;
	void	*wall_img;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_img;

typedef struct s_game
{
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		flood_exit;
	int		flood_collect;
	int		collectibles;
	int		exit;
	int		spawn;
	char	**map;
	int		pixel;
	int		collectibles_left;
	int		step_count;
	t_img	img;
}			t_game;

void	game_init(t_game *game);
int		check_open_file(t_game *game, char *file);
void	init_check_map(t_game *game, char *path);
int		init_map(t_game *game, char *file);
void	check_extension_file(t_game *game, char *file);
void	check_map_valid(t_game *game);
void	check_game(t_game *game);
void	check_game_utils(t_game *game, int exit, int collectibles, int spawn);
void	check_map(t_game *game);
void	check_wall_border(t_game *game);
int		check_map_height(char **map);
void	seed_fill(t_game *game, char **map, int x, int y);
void	ft_player(t_game *game);
void	see_fill_result(t_game *map_cpy);
char	**ft_copy(char **cpy, int height);
void	ft_message(const char *s);
void	is_empty(t_game *game);
void	print_error(t_game *game, const char *s);
void	free_map(t_game *game);
void	free_map_copy(char **copy, int height);
int		close_window(void *param);
int		close_game(t_game *game);
void	print_map(t_game *game);
void	initialize_img(t_img *img, t_game *game);
void	draw_map(t_game *game, t_img *img);
void	draw_second_map(t_game *game, t_img *img);
void	draw_map_exit(t_game *game, t_img *img);
void	draw_maps(t_game *game, t_img *img);
void	free_mlx_img(t_img *img);
int		keyboard(int keyb, t_game *game);
void	move_player(t_game *game, int new_x, int new_y);
void	collect_item(t_game *game, int x, int y);
void	destroy_img(void *mlx_ptr, void **img);

#endif