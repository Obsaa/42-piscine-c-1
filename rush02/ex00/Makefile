NAME = colle-2
SRC_DIR = srcs/
INCLUDES_DIR = includes/
FUNCTIONS = utilities printers ft_split_nl rush02_lib
BINS = $(patsubst %,%.o,$(FUNCTIONS))
FLAGS = -Wall -Werror -Wextra

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
