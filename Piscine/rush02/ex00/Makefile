# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maserrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 17:56:37 by maserrie          #+#    #+#              #
#    Updated: 2022/11/20 20:22:25 by maserrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c
SRCS += ft_error.c
SRCS += ft_print.c
SRCS += ft_read_file.c
SRCS += ft_basic.c
SRCS += ft_parse.c
SRCS += ft_free.c
SRCS += ft_print_num.c

CFLAGS = -Wall -Werror -Wextra -g

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

HEADER = ft.h

LIB = lib_basic.a

NAME = rush02

${NAME}: ${OBJS}
	${CC} -o ${NAME} -I ${HEADER} ${CFLAGS} ${OBJS} ${LIB}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
