# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maserrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 17:56:37 by maserrie          #+#    #+#              #
#    Updated: 2022/12/03 22:23:38 by maserrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ALIAS

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${BON:.c=.o}

CFLAGS = -Wall -Werror -Wextra -g

CC = gcc

RM = rm -f

HEADERS = ./

NAME = libft.a

#COLOR

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#SRCS

SRCS = ft_memset.c
SRCS += ft_bzero.c
SRCS += ft_memcpy.c
SRCS += ft_memmove.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_strlen.c
SRCS += ft_strlcpy.c
SRCS += ft_strdup.c
SRCS += ft_strlcat.c
SRCS += ft_strchr.c
SRCS += ft_strrchr.c
SRCS += ft_strnstr.c
SRCS += ft_strncmp.c
SRCS += ft_atoi.c
SRCS += ft_isalpha.c
SRCS += ft_isdigit.c
SRCS += ft_isalnum.c
SRCS += ft_isascii.c
SRCS += ft_isprint.c
SRCS += ft_toupper.c
SRCS += ft_tolower.c
SRCS += ft_striteri.c
SRCS += ft_strmapi.c
SRCS += ft_substr.c
SRCS += ft_strjoin.c
SRCS += ft_strtrim.c
SRCS += ft_split.c
SRCS += ft_itoa.c
SRCS += ft_putchar_fd.c
SRCS += ft_putstr_fd.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr_fd.c
SRCS += ft_calloc.c

BON = ft_lstnew.c
BON += ft_lstdelone.c
BON += ft_lstclear.c
BON += ft_lstadd_front.c
BON += ft_lstadd_back.c
BON += ft_lstsize.c
BON += ft_lstlast.c
BON += ft_lstiter.c
BON += ft_lstmap.c

#COMMANDES

.c.o:
	@${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	@ar rc ${NAME} ${OBJS}
	@echo "${BLUE}Belle librairie"

bonus: ${OBJS_BONUS}
	@ar rc ${NAME} ${OBJS_BONUS}
	@echo "${RED}Avec les bonus et tout, WAOUH"

all: ${NAME}

clean:
	@${RM} ${OBJS}
	@${RM} ${OBJS_BONUS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY = all clean fclean re
