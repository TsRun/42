# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maserrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 17:56:37 by maserrie          #+#    #+#              #
#    Updated: 2022/12/05 16:22:00 by maserrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line.c
SRCS += main.c

BONUS = get_next_line_bonus.c
BONUS += main_bonus.c

CFLAGS = -Wall -Werror -Wextra -g -D BUFFER_SIZE=100000

OBJS = ${SRCS:.c=.o}

OBJS_B = ${BONUS:.c=.o}

CC = gcc

RM = rm -f

NAME = next_line

${NAME}: ${OBJS}
	${CC} -o ${NAME} -I ${HEADER} ${CFLAGS} ${OBJS}

bonus: ${OBJS_B}
	${CC} -o ${NAME} -I ${HEADER} ${CFLAGS} ${OBJS_B}

all: ${NAME}

clean:
	${RM} ${OBJS}
	${RM} ${OBJS_B}

fclean: clean
	${RM} ${NAME}

re: fclean all
