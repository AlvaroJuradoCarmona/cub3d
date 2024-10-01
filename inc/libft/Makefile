# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsantama <fsantama@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 09:54:51 by fsantama          #+#    #+#              #
#    Updated: 2023/09/08 11:02:16 by fsantama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================#
#                        	GENERAL CONFIG & FLAGS                             #
# =============================================================================#

# PROGRAM FOR COMPILING C PROGRAMS
CC 		=	gcc

# C COMPILER FLAGS
CFLAGS =	-Werror -Wall -Wextra -g

NAME 	=	libft.a

# =============================================================================#
#                              MANDATORY PART                                  #
# =============================================================================#

SRC	=	ft_isalpha.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_strlen.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_strlcpy.c \
	  ft_strlcat.c \
	  ft_toupper.c \
	  ft_tolower.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strncmp.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strnstr.c \
	  ft_atoi.c \
	  ft_calloc.c \
	  ft_strdup.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_itoa.c \
	  ft_strmapi.c \
	  ft_striteri.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_split.c \

BNS_SRC = ft_lstnew_bonus.c \
		  ft_lstadd_front_bonus.c \
		  ft_lstsize_bonus.c \
		  ft_lstlast_bonus.c \
		  ft_lstadd_back_bonus.c \
		  ft_lstdelone_bonus.c \
		  ft_lstclear_bonus.c \
		  ft_lstiter_bonus.c \
		  ft_lstmap_bonus.c \
		  
OBJS	=	$(SRC:.c=.o)

BNS_OBJS := $(BNS_SRC:.c=.o)		  

# =============================================================================#
#                                  RULES                                       #  
# =============================================================================#

all : $(NAME) 

$(NAME):$(OBJS)
#	$(CC) $(CFLAGS) -c $(SRC)
	@ar rcs $(NAME) $(OBJS)
	
	@echo "$(CYAN) ======================================================="
	@echo "| 		  _     ___ ____  _____ _____ 		|"
	@echo "|		 | |   |_ _| __ )|  ___|_   _|		|"
	@echo "|		 | |    | ||  _ \| |_    | |  		|"
	@echo "|		 | |___ | || |_) |  _|   | |  		|"
	@echo "|		 |_____|___|____/|_|     |_|  		|"
	@echo "|		                              		|"
	@echo " ======================================================="
	@echo " ================ Develop by fsantama =================="
	@echo " ======================================================="
	@echo "																	"
	@echo "      (((/               /(((((,              .((((				"
	@echo "     ((,,,*((((((((((((((,,*,,,*(((((((((((((/   *(/				"
	@echo "     ((,,,,,,,,,,,,,,,,,,,,,,,,,,,,,(((..       .(((				"
	@echo "    ((/,,,,,,,,,,,,(##(####/,,,,*(((   *%, # ,(((%((				"
	@echo "    #(/,,,,,,,,,,*%##########(((/  #  ,*, *((#  %#((				"
	@echo "    /((,,,,/(#(###%##%%#,,,*,,,#,   // /((,,%%  %#((				"
	@echo "     (((###(##((#####%,,,/,*##,*#*  (((#%% ,%%  %(((				"
	@echo "     (((%##%%%%%%%#(((,,(/,((*#*,,((#. #%% ,%%  %((,				"
	@echo "      ((#%%%####(((* .,,,%/*,*/*,* %%. #%% ,%%  (((				"
	@echo "      ,((#%%%(((, *%, %((,,,/,,/#  %%. #%% ,%% (((				"
	@echo "       *(((((   ## (   *(((%( ,%%  %%. #%% ,%%(((				"
	@echo "        .((*  /*((  /(((%%%%( ,%%  %%. #%% ,%(((					"
	@echo "          (((    (((#%%%%%%%( ,%%  %%. #%% ,(((					"
	@echo "           ((((((#%%%%%%%%%%( ,%%  %%. #%%/((,					"
	@echo "             (((#%%%%%%%%%%%( ,%%  %%. ##(((						"
	@echo "              .(((%%%%%%%%%%( ,%%  %%. (((						"
	@echo "                ,(((%%%%%%%%( ,%%  %#(((							"
	@echo "                  .(((%%%%%%( ,%% .(((							"
	@echo "                     (((#%%%( ,%((((								"
	@echo "                       *(((%( (((.								"
	@echo "                          ((((*									"
	@echo "	                                                      			"
	@echo " =======================================================			"
	@echo "                                                       $(DEFAULT)"
	@echo "$(GREEN) $(NAME) make done ✅ $(DEFAULT)"

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BNS_OBJS)
	@ar rcs $(NAME) $(BNS_OBJS)

clean :
	@rm -f $(OBJS) $(BNS_OBJS)
	
fclean : clean
	@rm -f $(NAME)
	
re: fclean all

# PERSONAL USE

git:
	git add *
	git commit -m "Some changes made"
	git push
	git ls-files

# =============================================================================#
#                                 COLORS                                       #
# =============================================================================#

BOLD	:=	\033[1m
BLACK	:=	\033[30;1m
RED		:=	\033[31;1m
GREEN	:=	\033[32;1m
YELLOW	:=	\033[33;1m
BLUE	:=	\033[34;1m
MAGENTA	:=	\033[35;1m
CYAN	:=	\033[36;1m
WHITE	:=	\033[37;1m
DEFAULT	:=	\033[0m

.PHONY: all clean fclean re bonus git