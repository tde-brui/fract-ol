NAME = fractol
CFLAGS = -Wall -Wextra -Werror
CC = gcc
LIBS = MLX42/build/libmlx42.a libft/libft.a -ldl -lglfw3 -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit
HEADER = -I ./include -I MLX42/include
MLX = MLX42/
SOURCES = main.c \
	hooks.c \
	mandelbrot.c \
	utils.c \
	input.c
OBJECT = $(SOURCES:.c=.o)

all: libmlx $(NAME)

libmlx:
	cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)

$(NAME): $(OBJECT)
	make -C libft
	$(CC) $(OBJECT) $(LIBS) $(HEADERS) -o $(NAME)

clean: 
	rm -rf $(OBJECT)
	rm -rf MLX42/build
	make fclean -C libft

fclean: clean
	rm -rf $(NAME)

re: fclean all