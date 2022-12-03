# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maserrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 17:56:37 by maserrie          #+#    #+#              #
#    Updated: 2022/12/02 22:15:10 by maserrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c
SRCS += get_next_line.c

CFLAGS = -Wall -Werror -Wextra -g -D BUFFER_SIZE=32000

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

HEADER = ft.h

NAME = next_line

${NAME}: ${OBJS}
	${CC} -o ${NAME} -I ${HEADER} ${CFLAGS} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
