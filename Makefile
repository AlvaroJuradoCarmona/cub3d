# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 12:44:44 by fsantama          #+#    #+#              #
#    Updated: 2024/07/31 12:44:44 by fsantama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================#
#                        	GENERAL CONFIG & FLAGS                             #
# =============================================================================#

NAME = cub3d

SRC_DIR = src
SRC = cub3d.c \
        utils/ft_init_data.c \
        parse/ft_parse_data.c \
        utils/ft_error.c \

# =============================================================================#
#                              MANDATORY PART                                  #
# =============================================================================#

SRCS = inc/get_next_line/get_next_line.c \
			inc/get_next_line/get_next_line_utils.c \
			src/parse/ft_parse_data.c \
			src/utils/ft_error.c \
			src/utils/ft_init_data.c \
			src/utils/ft_print_header.c \
			src/cub3d.c \

OBJS = $(SRCS:.c=.o)

INC_LFT = -Ilibft
LIBFT_D = inc/Libft
LIBFT = $(LIBFT_D)/libft.a
PRINTF 	=	./inc/ft_printf/libftprintf.a

MLX_DIR = inc/MLX42
LIBMLXL = libmlx42.a
LIBMLX = $(MLX_DIR)/libmlx42.a #-ldl -lglfw -pthread -lm
INC_MLX = -I$(MLX_DIR)/include/MLX42 -Iinclude -ldl -lglfw -pthread -lm
#INC_MLX = -I$(MLX_DIR)/include/MLX42 #-Iinclude -lglfw -L"/Users/$$USER/.brew/opt/glfw/lib/"

HEADERS = -Iinclude $(INC_LFT)

INC = $(HEADERS) $(INC_MLX)

CC = gcc
FLAGS = -Wall -Werror -Wextra -g

RM = rm -f

GREEN = "\033[32m"
VIOLET = "\033[35m"
YELLOW = "\033[33m"
RED = "\033[31m"
NOCOLOR = "\033[0m"

all: $(LIBMLXL) $(LIBFT) $(PRINTF) $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) inc/cub3d.h
	@echo $(YELLOW)Norminette cub3d...$(NOCOLOR)
#	@norminette src
	@$(CC) $(FLAGS) $(INC) $(SRCS) $(LIBMLX) $(LIBFT) $(PRINTF) -o $(NAME) -g
	@echo $(GREEN)Program $(NAME) ready$(NOCOLOR)

$(LIBMLXL):
	@echo $(VIOLET)Lib MLX42 compilation...$(NOCOLOR)
	@make -C $(MLX_DIR) --silent
	@echo $(GREEN)Library MLX42 ready$(NOCOLOR)

$(LIBFT):
	@echo $(VIOLET)Libft compilation...$(NOCOLOR)
	@if [ -d "$(LIBFT_D)" ]; then \
		make -C $(LIBFT_D) --silent; \
		make bonus -C $(LIBFT_D) --silent; \
		echo $(GREEN)Libft ready$(NOCOLOR); \
	else \
		echo $(RED)Error: libft directory not found!$(NOCOLOR); \
		exit 1; \
	fi

$(PRINTF): 
	@make  -C inc/ft_printf > /dev/null

clean:
	@$(RM) $(OBJS)
#	@$(RM) $(OBJS_BONUS)
	@$(RM) $(SRC_DIR)/get_next_line.o
	@make clean -C $(MLX_DIR) --silent
	@make clean -C $(LIBFT_D) --silent
	@echo Objects files $(RED)cleaned$(NOCOLOR)

fclean: clean
	@$(RM) $(NAME)
#	@$(RM) $(NAME_BONUS)
	@make fclean -C $(LIBFT_D) --silent
	@make -C inc/ft_printf clean > /dev/null
	@echo Executables files $(RED)cleaned$(NOCOLOR)

re: fclean all
	@echo $(RED)Cleaned$(NOCOLOR) and $(GREEN)rebuilt$(NOCOLOR) $(NAME) project

.PHONY: all clean fclean re
