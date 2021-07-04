NAME := fdf
LIBFT_NAME = libft.a
GNL_NAME = gnl.a
MLX_NAME = libmlx.a

SRCS = fdf.c \
	./srcs/bresenham.c \
	./srcs/bresenham_utils.c \
	./srcs/map_error_ctrl.c \
	./srcs/line_error_control.c \
	./srcs/error_msg.c \
	./srcs/get_nbr_and_color.c \
	./srcs/gradient_coloring.c \
	./srcs/get_map_line.c
OBJS = ${SRCS:.c=.o}

LIBFT_DIR := ./libft/
GNL_DIR := ./get_next_line/
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

$(NAME): $(LIBFT_DIR)$(LIBFT_NAME) $(MLX_DIR)$(MLX_NAME) $(GNL_DIR)$(GNL_NAME) $(OBJS)
	$(CC) -o $(NAME)  $^ -I $(INC_DIR) -framework OPENGL -framework Appkit -lm

$(LIBFT_DIR)$(LIBFT_NAME): $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

$(GNL_DIR)$(GNL_NAME): $(GNL_DIR)
	make -C $(GNL_DIR)

$(MLX_DIR)$(MLX_NAME): $(MLX_DIR)
	make -C $(MLX_DIR)

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	make -C $(GNL_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
