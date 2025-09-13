SO_LONG_NAME = so_long
BONUS_NAME = so_long_bonus

CC = cc
FLAG = -Wall -Wextra -Werror -g3

LIBFT_PATH = libft
LIBFT_FILE = libft.a
LIBFT_LIB = $(LIBFT_PATH)/$(LIBFT_FILE)

MLX_PATH = minilibx-linux
MLX_FLAGS = -lX11 -lXext -fPIE
MLX_FILE = libmlx.a
MLX_LIB = $(MLX_PATH)/$(MLX_FILE)
MLX_EX = $(MLX_LIB) $(MLX_FLAGS)

SO_LONG_SRC = src/so_long.c src/check_map.c src/init.c src/free_game.c src/back_tracking.c \
              src/utils.c src/player_moves.c src/helper.c
SO_LONG_OBJ = $(SO_LONG_SRC:.c=.o)

BONUS_SRC = bonus/so_long_bonus.c bonus/check_map_bonus.c bonus/init_bonus.c bonus/free_game_bonus.c bonus/back_tracking_bonus.c \
            bonus/utils_bonus.c bonus/player_moves_bonus.c bonus/helper_bonus.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

.c.o:
	@printf "\r\033[K[so_long] \033[0;32mBuilding : $<\033[0m"
	@$(CC) $(FLAG) -c $< -o $@

all: $(SO_LONG_NAME)

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(MLX_LIB):
	@printf "\r\033[K[mlx] \033[0;32mLinking...\033[0m"
	@make -sC $(MLX_PATH)

$(SO_LONG_NAME): $(LIBFT_LIB) $(MLX_LIB) $(SO_LONG_OBJ)
	@printf "\r\033[K[so_long] \033[0;32mLinking...\033[0m"
	@$(CC) $(SO_LONG_OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(SO_LONG_NAME) -lm
	@printf "\r\033[K[so_long] \033[0;32mDone!\033[0m\n"

bonus: $(LIBFT_LIB) $(MLX_LIB) $(BONUS_OBJ)
	@printf "\r\033[K[bonus] \033[0;32mLinking...\033[0m"
	@$(CC) $(BONUS_OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(BONUS_NAME) -lm
	@printf "\r\033[K[bonus] \033[0;32mDone!\033[0m\n"

clean:
	@make clean -sC $(LIBFT_PATH)
	@make clean -sC $(MLX_PATH)
	@rm -f $(SO_LONG_OBJ) $(BONUS_OBJ)
	@printf "[So_long] \033[1;31mCleaned .o!\033[0m\n"

fclean: clean
	@rm -f $(SO_LONG_NAME) $(BONUS_NAME)
	@make fclean -C $(LIBFT_PATH)
	@printf "[So_long] \033[1;31mCleaned all!\033[0m\n"

re: fclean all

.PHONY: all clean fclean re bonus