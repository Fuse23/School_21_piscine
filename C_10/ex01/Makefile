# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: falarm <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 18:05:52 by falarm            #+#    #+#              #
#    Updated: 2021/08/02 18:37:54 by falarm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= main.c

OBJS	= ${SRC:.c=.o}

NAME	= ft_cat

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -g

RM		= rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

.PHONY: all clean fclean .c.o
