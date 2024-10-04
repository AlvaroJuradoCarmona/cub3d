#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 12:44:44 by fsantama          #+#    #+#              #
#    Updated: 2024/10/02 10:20:41 by fsantama         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# =============================================================================#
#                              MANDATORY PART                                  #
# =============================================================================#

NAME = cub3d
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42
INCLUDES = -I $(LIBFT) -I $(GNL) -I $(MLX)/include
LIBFT = inc/libft
LIBFT_A = $(LIBFT)/libft.a
GNL = inc/get_next_line
MLX = inc/MLX42
MLX_A = $(MLX)/libmlx42.a
EXTRA_FLAGS = -lglfw -lm -ldl -pthread
EXTRA_F42 = -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/ ${MLX_A} ${LIBFT_A}

SRCS_GNL = $(GNL)/get_next_line.c $(GNL)/get_next_line_utils.c
SRCS = src/parse/ft_check_map.c \
			src/parse/ft_map_construct.c \
			src/parse/ft_map_normalize.c \
			src/parse/ft_parse_data.c \
			src/parse/ft_parse_identifiers.c \
			src/parse/ft_parse_map.c \
			src/parse/ft_read_map.c \
			src/raycasting/raycasting.c \
			src/utils/ft_error.c \
			src/utils/ft_free_and_join.c \
			src/utils/ft_free_and_null.c \
			src/utils/ft_free.c \
			src/utils/ft_init_data.c \
			src/utils/ft_init_images.c \
			src/utils/ft_initial_cleaner.c \
			src/utils/ft_put_rgbcolor.c \
			src/utils/ft_put_rgbimg.c \
			src/utils/ft_split_free.c \
			src/utils/ft_split_size.c \
			src/utils/ft_cleaner.c \
			src/utils/ft_cursor_hook.c \
			src/utils/ft_loop_hooks.c \
			src/utils/ft_swap.c \
			src/utils/ft_iswall.c \
			src/cub3d.c \
			$(SRCS_GNL)

OBJS = $(SRCS:.c=.o)
RM = rm -f

all: libft mlx $(NAME)

libft:
	make -C $(LIBFT)

mlx:
	make -C $(MLX)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(SRCS) $(LIBFT_A) $(MLX_A) $(INCLUDES) $(EXTRA_FLAGS) $(EXTRA_F42) -o $(NAME)

clean: 
	make clean -C $(LIBFT)
	make clean -C $(MLX)
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(LIBFT_A)
	$(RM) $(MLX_A)
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re libft mlx
