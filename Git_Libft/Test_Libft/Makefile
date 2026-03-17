NAME = test

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = ../libft.a
INCLUDE = -I..

SRC = test_ft_atoi.c test_ft_memchr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(INCLUDE) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

run: all
	./$(NAME)

#clean:
#	rm -f $(OBJ)

#fclean: clean
#	rm -f $(NAME)

clean:
	del /Q $(OBJ) 2>nul

fclean: clean
	del /Q $(NAME).exe 2>nul

re: fclean all