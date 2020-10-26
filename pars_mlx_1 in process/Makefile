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
		raycasting.c \
		get_positions.c \
		screenshot.c \
		main.c \
		sprites.c

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

$(NAME): $(OBJ) $(HEADER)
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


# NAME = cub3D

# HEADER = cub3d.h

# SRCS =	./src/parsing.c \
# 		./src/parsing_map.c\
# 		./src/check_cipher.c \
# 		./src/parsing_convert.c \
# 		./src/errors.c \
# 		./src/inits.c \
# 		./src/drawing.c \
# 		./src/calculations.c \
# 		./src/player_move.c \
# 		./src/raycasting.c \
# 		./src/get_positions.c \
# 		./src/sprites.c \
# 		./src/main.c 

# # OBJ = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

# # OBJ_DIR = obj
# # SRC_DIR = src
# # LIBFT_DIR = libft
# # LIBFT = libft.a
# # MLX_DIR = mlx
# # MLX = libmlx.dylib

# # CFLAGS = -Wall -Wextra -Werror -g

# # all:  $(NAME)
# # 	$(MAKE) -C $(MLX_DIR)
# # 	$(MAKE) -C $(LIBFT_DIR)
# # 	$(MAKE) -j $(NAME) 

# # $(NAME): $(OBJ) $(HEADER)
# # 		@gcc $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX_DIR) -l mlx -L $(LIBFT_DIR) -l ft
# # 		@install_name_tool -change $(MLX) @loader_path/$(MLX_DIR)/$(MLX) $(NAME)
# # 		@echo $(NAME) : Молодец, всё зашло

# # $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(MLX_DIR)/$(MLX) $(LIBFT_DIR)/$(LIBFT)
# # 		@mkdir -p $(OBJ_DIR)
# # 		@gcc $(CFLAGS) -I $(MLX_DIR) -I $(LIBFT_DIR) -c $< -o $@

# # clean:
# # 	$(MAKE) clean -C $(MLX_DIR)
# # 	$(MAKE) clean -C $(LIBFT_DIR)
# # 	rm -rf $(OBJ_DIR)

# # fclean:	clean
# # 	rm -rf $(LIBFT_DIR)/$(LIBFT)
# # 	rm -rf $(NAME)

# # re: fclean all

# # .PHONY: all, clean, fclean, re

# OBJS = $(SRCS:.c=.o)

# CC = gcc

# CFLAGS = -Wall -Wextra -Werror -c -g

# LIBFT_ARC = libft/libft.a
# MLX_ARC = ./mlx/libmlx.a

		
# all: $(NAME)

# $(NAME): $(OBJS) $(LIBFT_ARC) $(MLX_ARC) $(HEADER)
# 	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -Llibft -lft $(OBJS) -o $(NAME)

# %.o: %.c
# 	$(CC) $(CFLAGS) -Imlx -Ilibft $< -o $@

# $(LIBFT_ARC):
# 	make -C libft

# $(MLX_ARC):
# 	make -C mlx

# clean:
# 	make clean -C libft
# 	rm -f $(OBJS)
# fclean: clean
# 	make fclean -C libft
# 	rm -f $(NAME)
# re: fclean all

# .PHONY: all clean fclean re