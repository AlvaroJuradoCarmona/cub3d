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

NAME = cub3d

SRC_DIR = src
#SRCS = $(wildcard $(SRC_DIR)/*.c)
SRC = cub3d.c \
		utils/ft_init_data.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))

OBJS = $(SRCS:.c=.o)

INC_LFT = -Ilibft
#LIBFT_D = libft
#LIBFT = $(LIBFT_D)/libft.a


MLX_DIR = inc/MLX42
LIBMLXL = libmlx42.a
LIBMLX = $(MLX_DIR)/libmlx42.a #-ldl -lglfw -pthread -lm
INC_MLX = -I$(MLX_DIR)/include/MLX42 -Iinclude -ldl -lglfw -pthread -lm
#INC_MLX = -I$(MLX_DIR)/include/MLX42 #-Iinclude -lglfw -L"/Users/$$USER/.brew/opt/glfw/lib/"


HEADERS = -Iinclude $(INC_LFT)

INC = $(HEADERS) $(INC_MLX)

CC = clang
FLAGS = -Wall -Werror -Wextra -g

RM = rm -f

GREEN = "\033[32m"
VIOLET = "\033[35m"
YELLOW = "\033[33m"
RED = "\033[31m"
NOCOLOR = "\033[0m"

all: $(LIBMLXL) $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT) inc/cub3d.h
	@echo $(YELLOW)Norminette cub3d...$(NOCOLOR)
#	@norminette src
	@$(CC) $(FLAGS) $(INC) $(SRCS) $(LIBMLX) $(LIBFT) -o $(NAME) -g
	@echo $(GREEN)Program $(NAME) ready$(NOCOLOR)

$(LIBMLXL):
	@echo $(VIOLET)Lib MLX42 compilation...$(NOCOLOR)
	@make -C $(MLX_DIR) --silent
	@echo $(GREEN)Library MLX42 ready$(NOCOLOR)

#bonus: $(LIBFT) $(LIBMLXL) $(NAME_BONUS)

$(LIBFT):
	@echo $(VIOLET)Libft compilation...$(NOCOLOR)
	@make -C $(LIBFT_D) --silent
	@make bonus -C $(LIBFT_D) --silent
	@echo $(GREEN)Libft ready$(NOCOLOR)

#$(NAME_BONUS): $(OBJS_BONUS) $(GNL_OBJS)
#	@echo $(YELLOW)Norminette...$(NOCOLOR)
#	@norminette src_bonus
#	@$(CC) $(FLAGS) $(INC) $(LIBMLX) $(LIBFT) $(SRCS_BONUS) $(SRC_GNL) -o $(NAME_BONUS)
#	@echo $(GREEN)Program $(NAME_BONUS) ready$(NOCOLOR)


clean:
	@$(RM) $(OBJS)
#	@$(RM) $(OBJS_BONUS)
	@$(RM) $(GNL_DIR)/get_next_line.o
	@make clean -C $(MLX_DIR) --silent
#	@make clean -C libft --silent
	@echo Objects files $(RED)cleaned$(NOCOLOR)

fclean: clean
	@$(RM) $(NAME)
#	@$(RM) $(NAME_BONUS)
	@$(RM) $(LIBFT)
	@echo Executables files $(RED)cleaned$(NOCOLOR)

re: fclean all
	@echo $(RED)Cleaned$(NOCOLOR) and $(GREEN)rebuilt$(NOCOLOR) $(NAME) project

#re_bonus: fclean bonus
#	@echo $(RED)Cleaned$(NOCOLOR) and $(GREEN)rebuilt$(NOCOLOR) $(NAME_BONUS) project

.PHONY: all clean fclean re #re_bonus