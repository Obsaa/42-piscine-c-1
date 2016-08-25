NAME = do-op
SRC_DIR = srcs/
INCLUDES_DIR = includes/
FUNCTIONS = ft_add ft_sub ft_mul ft_div ft_mod printers ft_atoi
FLAGS=-Wall -Wextra -Werror
BINS = $(patsubst %,%.o,$(FUNCTIONS))

.PHONY: all clean fclean re

all: $(NAME)

$(BINS):
	gcc -I$(INCLUDES_DIR) $(FLAGS) -c $(patsubst %.o,$(SRC_DIR)%.c,$@)

$(NAME): $(BINS)
	gcc -I$(INCLUDES_DIR) $(FLAGS) main.c $(BINS) -o $(NAME)

clean:
	/bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
