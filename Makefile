# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edavid <edavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 10:29:39 by edavid            #+#    #+#              #
#    Updated: 2021/08/02 10:29:39 by edavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = a.out
LIBNAME = libftprintf.a
SRC = ft_printf.c ft_print_character.c ft_print_string.c ft_print_pointer.c \
ft_print_integer.c ft_print_unsigned.c tester.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(MAKE) --directory=Mylib
	cp Mylib/libmylib.a .
	ar rs libmylib.a *.o
	rm -f *.o
	mv libmylib.a $(LIBNAME)
	$(CC) $(GCC) -o $@ $(LIBNAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: fclean re
fclean:
	$(MAKE) fclean --directory=Mylib
	rm -f $(NAME)
re:
	make fclean
	make
all: $(NAME)