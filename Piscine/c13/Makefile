# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maserrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 17:56:37 by maserrie          #+#    #+#              #
#    Updated: 2022/11/24 16:16:55 by maserrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c
SRCS += ex00/btree_create_node.c
SRCS += ex01/btree_apply_prefix.c
SRCS += ex02/btree_apply_infix.c
SRCS += ex03/btree_apply_suffix.c
SRCS += ex04/btree_insert_data.c
SRCS += ex05/btree_search_item.c
SRCS += ex06/btree_level_count.c
SRCS += ex07/btree_apply_by_level.c

CFLAGS = -Wall -Werror -Wextra -g

OBJS = ${SRCS:.c=.o}

CC = cc

RM = rm -f

LIB = lib_mathis.a

NAME = chained_list

${NAME}: ${OBJS}
	${CC} -o ${NAME} -I ${HEADER} ${CFLAGS} ${OBJS} ${LIB}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
