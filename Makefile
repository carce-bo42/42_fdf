NAME := fdf
NAME_BONUS := fdf_bonus
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

FILES_BONUS = bresenham_bonus \
			 bresenham_utils_bonus \
			 map_error_ctrl_bonus \
			 parser_bonus \
			 parser_utils_bonus \
			 error_msg_bonus \
			 gradient_coloring_bonus \
			 get_nbr_and_color_bonus \
			 get_map_line_bonus \
			 keycodes_bonus \
			 main_bonus \
			 drawer_bonus \
			 rotation_bonus

SRCS_DIR = ./srcs/
SRCS_DIR_BONUS = ./srcs_bonus/
LIBFT_DIR := ./libft/
GNL_DIR := ./get_next_line/
INC_DIR := ./includes/
EXE_DIR = ./
MLX_DIR = ./mlx/

SRCS = $(addsuffix .c, $(addprefix $(SRCS_DIR), $(FILES)))
SRCS_BONUS = $(addsuffix .c, $(addprefix $(SRCS_DIR_BONUS), $(FILES_BONUS)))
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC := cc
GCC := gcc
CFLAGS := -Wall -Werror -Wextra
MV := mv -f
RM := rm -f

%.o: %.c
	$(CC)  $(CFLAGS) -c $< -I $(INC_DIR)  -o $@ #-fsanitize=address

$(NAME): $(LIBFT_DIR)$(LIBFT_NAME) $(MLX_DIR)$(MLX_NAME) $(GNL_DIR)$(GNL_NAME) $(OBJS)
	$(CC) -o $(NAME)  $^ -I $(INC_DIR) -framework OPENGL -framework Appkit -lm #-fsanitize=address

$(NAME_BONUS): $(LIBFT_DIR)$(LIBFT_NAME) $(MLX_DIR)$(MLX_NAME) $(GNL_DIR)$(GNL_NAME) $(OBJS_BONUS)
	$(CC) -o $(NAME_BONUS)  $^ -I $(INC_DIR) -framework OPENGL -framework Appkit -lm -fsanitize=address

bonus: $(NAME_BONUS)

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
	$(RM) $(OBJS_BONUS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: clean all

tag: 
	ctags */*.c *.c *.h */*.h

.PHONY: all clean fclean re
