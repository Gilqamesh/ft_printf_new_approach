CFLAGS = 
CC = gcc
NAME = a.out
SRC = ft_printf.c ft_print_character.c ft_print_string.c ft_print_pointer.c \
tester.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(MAKE) --directory=Mylib
	cp Mylib/libmylib.a .
	ar rs libmylib.a *.o
	rm -f *.o
	$(CC) $(GCC) -o $@ libmylib.a
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: fclean
fclean:
	$(MAKE) fclean --directory=Mylib