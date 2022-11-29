# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maserrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 17:56:37 by maserrie          #+#    #+#              #
#    Updated: 2022/11/29 01:32:32 by maserrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c
SRCS += ft_memset.c
SRCS += ft_bzero.c
SRCS += ft_memcpy.c
SRCS += ft_memccpy.c
SRCS += ft_memmove.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_strlen.c
SRCS += ft_strdup.c
SRCS += ft_strcpy.c
SRCS += ft_strncpy.c
SRCS += ft_strcat.c
SRCS += ft_strncat.c

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
