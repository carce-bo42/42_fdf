NAME := fdf
LIBFT_NAME = libft.a
GNL_NAME = gnl.a
MLX_NAME = libmlx.a

FILES = main \
	bresenham \
	bresenham_utils \
	map_error_ctrl \
	parser \
	parser_utils \
	error_msg \
	get_nbr_and_color \
	gradient_coloring \
	get_map_line \
	drawer

SRCS_DIR = ./srcs/
LIBFT_DIR := ./libft/
GNL_DIR := ./get_next_line/
INC_DIR := ./includes/
EXE_DIR = ./
MLX_DIR = ./mlx/

SRCS = $(addsuffix .c, $(addprefix $(SRCS_DIR), $(FILES)))
OBJS = ${SRCS:.c=.o}

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
	$(RM) ./tags
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean
	$(RM) $(NAME)

re: clean all

tag: 
	ctags ./srcs/*.c ./fdf.c

.PHONY: all clean fclean re
