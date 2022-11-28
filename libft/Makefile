# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maserrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 17:56:37 by maserrie          #+#    #+#              #
#    Updated: 2022/11/28 21:46:01 by maserrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c
SRCS += ft_memset.c
SRCS += ft_bzero.c
SRCS += ft_memcpy.c
SRCS += ft_memccpy.c
SRCS += ft_memmove.c
SRCS += ft_memchr.c

CFLAGS = -Wall -Werror -Wextra -g

OBJS = ${SRCS:.c=.o}

CC = gcc

RM = rm -f

HEADER = ft.h

NAME = ft_test

${NAME}: ${OBJS}
	${CC} -o ${NAME} -I ${HEADER} ${CFLAGS} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
