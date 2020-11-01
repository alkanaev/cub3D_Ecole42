SRCS	= ft_strlen.c \
		ft_isalnum.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strchr.c \
		ft_bzero.c \
		ft_calloc.c \
		../new_gnl/get_next_line.c

OBJS    = ${SRCS:.c=.o}

CC      = gcc

CFLAGS  = -Wall -Wextra -Werror

NAME    = libft.a

.c.o :       ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}		:	${OBJS}
				ar rc ${NAME} ${OBJS}
				ranlib ${NAME}

all 		:   ${NAME}

clean 		:
				rm -f ${OBJS} 

fclean 		:	clean
				rm -f ${NAME}

re 			:   fclean all

.PHONY		:	all clean fclean re