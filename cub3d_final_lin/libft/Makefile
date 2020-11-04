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

OBJS    = ${SRCS:.c=.o}

CC      = /usr/bin/clang
RM = /bin/rm -f
AR = /usr/bin/ar

CFLAGS  = -Wall -Wextra -Werror

NAME    = libft.a

.c.o :       ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}		:	${OBJS}
				$(AR) rc ${NAME} ${OBJS}

all 		:   ${NAME}

clean 		:
				$(RM) ${OBJS} 

fclean 		:	clean
				$(RM) ${NAME}

re 			:   fclean all

.PHONY		:	all clean fclean re