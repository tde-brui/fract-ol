NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCE = \
	ft_printf.c \
	ft_unsigned_dec.c \
	ft_get_int.c \
	ft_printf.c \
	ft_lower_hexa.c \
	ft_upper_hexa.c \
	ft_put_addr.c \
	ft_utils.c

OBJECT = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	ar -cr $(NAME) $(OBJECT)

%.o: %.c
	$(CC) $(CFLAGS) -c  $< -o $@ -I libft/libft.a

clean: 
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all
