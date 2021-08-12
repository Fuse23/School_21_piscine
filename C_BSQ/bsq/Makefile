SRCS		= ft_create.c ft_fast_square.c ft_print_matrix.c ft_read_1.c ft_read_2.c ft_read_3.c ft_read_4.c ft_read.c ft_print2.c

OBJS		= ${SRCS:.c=.o}

NAME		= bsq

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${SRCS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re .c.o
