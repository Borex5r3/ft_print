# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbaich <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 18:25:03 by adbaich           #+#    #+#              #
#    Updated: 2021/11/23 19:52:00 by adbaich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c \
	   ft_putadr.c \
	   ft_putchar_fd.c \
	   ft_putnbr_base.c \
	   ft_putnbr_bexa.c \
	   ft_putnbr_fd.c \
	   ft_putnbr_hexa.c \
	   ft_putstr_fd.c \

OBJS = ft_printf.o \
	   ft_putadr.o \
	   ft_putchar_fd.o \
	   ft_putnbr_base.o \
	   ft_putnbr_bexa.o \
	   ft_putnbr_fd.o \
	   ft_putnbr_hexa.o \
	   ft_putstr_fd.o \

NAME = libftprintf.a

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}:
	${CC} ${FLAGS} -c ${SRCS}
	ar rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
