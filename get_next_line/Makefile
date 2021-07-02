NAME = gnl.a

CFLAGS = -Wall -Werror -Wextra

CC = cc

SRC = get_next_line.c \
	  get_next_line_utils.c

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

clean:
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME)

re: fclean all bonus

.PHONY: all bonus clean fclean re
