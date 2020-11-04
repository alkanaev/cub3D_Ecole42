NAME = cub3D

HEADER = .
LIB1 = libft/libft.a
LIB2 = mlx/libmlx.a

PATH = src/

SRC =	parsing_cub_1.c \
		parsing_cub_2.c \
		parsing_cub_3.c \
		check_ciphers_1.c \
		check_ciphers_2.c \
		parsing_convert_1.c \
		parsing_convert_2.c \
		calculate_walls.c \
		draw_sprites.c \
		drawing.c \
		get_positions.c \
		get_texture_data.c \
		init_array_params.c \
		inits.c \
		errors.c \
		player_move.c \
		raycasting.c \
		screenshot.c \
		shortest_dist.c \
		sprites_calculations.c \
		sprites_data.c \
		wall_cross.c \
		utils.c \
		texture_valid.c \
		main.c \
		
CC = /usr/bin/clang
CFLAGS = -Wall -Wextra -Werror -I $(HEADER) -L/usr/include/../lib -lXext -lX11 -lm -lbsd
MAKE = /usr/bin/make
RM = /bin/rm -f
LIBDIR = libft
LIBMLX = mlx

OBJ = $(addprefix $(PATH), $(SRC))

$(NAME): $(OBJ)
		@cd $(LIBDIR) && $(MAKE) re && $(MAKE) clean
		$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(LIB1) $(LIB2)
		@echo $(NAME) : Fine!

all: $(NAME)

clean 		:
				$(RM) $(LIB1)
				@echo "Clean done"

fclean 		:	clean
				$(RM) ${NAME}
				@echo "Fclean done"

re 			:   fclean all

.PHONY: all, clean, fclean, re