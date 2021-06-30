NAME := fdf
LIBFT_NAME = libft.a
MLX_NAME = libmlx.a

SRCS = fdf.c

OBJS = ${SRCS:.c=.o}

LIBFT_DIR := ./libft/
INC_DIR := ./includes/
EXE_DIR = ./
MLX_DIR = ./mlx/

CC := cc
GCC := gcc
CFLAGS := -Wall -Werror -Wextra
MV := mv -f
RM := rm -f

%.o: %.c
	$(CC)  $(CFLAGS) -c $< -I $(INC_DIR)  -o $@

$(NAME): $(LIBFT_DIR)$(LIBFT_NAME) $(MLX_DIR)$(MLX_NAME) $(OBJS)
	$(CC) -o $(NAME)  $^ -I $(INC_DIR) -framework OPENGL -framework Appkit -lm

$(LIBFT_DIR)$(LIBFT_NAME): $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

$(MLX_DIR)$(MLX_NAME): $(MLX_DIR)
	make -C $(MLX_DIR)

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re

