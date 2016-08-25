NAME = libft.a
SRC_DIR = srcs/
INCLUDES_DIR = includes/
FUNCTIONS = ft_putchar ft_putstr ft_strcmp ft_strlen ft_swap
BINS = $(patsubst %,%.o,$(FUNCTIONS))

.PHONY: all clean fclean re

all: $(NAME)

$(BINS):
	gcc -I=$(INCLUDES_DIR) -Wall -Wextra -Werror -c $(patsubst %.o,$(SRC_DIR)%.c,$@)

$(NAME): $(BINS)
	ar rc $(NAME) $(BINS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
