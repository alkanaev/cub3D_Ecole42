NAME = cub3d

HEADER = cub3d.h

SRCS =	parsing.c \
		parsing_map.c\
		check_cipher.c \
		parsing_convert.c \
		errors.c \
		inits.c \
		drawing.c \
		calculations.c \
		player_move.c \
		main.c

OBJ = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

OBJ_DIR = obj
SRC_DIR = src
LIBFT_DIR = libft
LIBFT = libft.a
MLX_DIR = mlx
MLX = libmlx.dylib

CFLAGS = -Wall -Wextra -Werror -g

all:
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -j $(NAME)

$(NAME): $(OBJ)
		@gcc $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX_DIR) -l mlx -L $(LIBFT_DIR) -l ft
		@install_name_tool -change $(MLX) @loader_path/$(MLX_DIR)/$(MLX) $(NAME)
		@echo $(NAME) : Молодец, всё зашло

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(MLX_DIR)/$(MLX) $(LIBFT_DIR)/$(LIBFT)
		@mkdir -p $(OBJ_DIR)
		@gcc $(CFLAGS) -I $(MLX_DIR) -I $(LIBFT_DIR) -c $< -o $@

clean:
	$(MAKE) clean -C $(MLX_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -rf $(LIBFT_DIR)/$(LIBFT)
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re