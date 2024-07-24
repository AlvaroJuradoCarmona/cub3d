# Nombre del ejecutable
NAME = cub3d

# Compilador y banderas
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Rutas
MLX_DIR = inc/MLX42
MLX_LIB = $(MLX_DIR)/libmlx42.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx42 -lm -lXext -lX11 -lglfw
INCLUDES = -I$(MLX_DIR) -Iinclude

# Fuentes
SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

# Reglas
all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(INCLUDES)
	@echo "Executable $(NAME) created successfully."

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)
	@echo "MLX library $(MLX_LIB) created successfully."

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean
	@echo "Cleaned up object files and MLX library."

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MLX_DIR) clean
	@echo "Removed executable and MLX library."

re: fclean all

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "Compiling $<"

.PHONY: all clean fclean re
