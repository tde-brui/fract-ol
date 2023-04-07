NAME = fractol
CFLAGS = -Wall -Wextra -Werror
CC = gcc
SOURCES = main.c \
	hooks.c \
	mandelbrot.c \
	utils.c
OBJECT = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBECT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJECT)

fclean: clean
	rm -rf $(NAME)

re: fclean all