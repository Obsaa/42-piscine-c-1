NAME	=	bsq
CC		=	gcc

D_SRC	= 	src
D_INC	=	includes
D_OBJ	=	obj

O_FLAGS	=	-O3
W_FLAGS	=	-Wall -Wextra -Werror
DEBUG	=
MKDIR	=	mkdir -p
RM		=	/bin/rm -rf

F_SRC	:=	$(shell ls -1 $(D_SRC) | grep .c$$)
F_OBJ	:=	$(F_SRC:.c=.o)
F_OBJ	:=	$(addprefix $(D_OBJ)/, $(F_OBJ))

.PHONY: all clean fclean re

all: $(NAME)

$(D_OBJ)/%.o: $(D_SRC)/%.c $(D_INC)
	@$(MKDIR) $(D_OBJ)
	$(CC) -I$(D_INC) $(O_FLAGS) $(W_FLAGS) -c $< -o $@ $(DEBUG)

$(NAME): $(F_OBJ)
	$(CC) -I$(D_INC) $(O_FLAGS) $(W_FLAGS) $(F_OBJ) -o $@ $(DEBUG)

clean:
	$(RM) $(D_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
