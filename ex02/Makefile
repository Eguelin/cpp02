# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 16:35:50 by eguelin           #+#    #+#              #
#    Updated: 2023/11/29 14:41:17 by eguelin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re
.SILENT:

# **************************************************************************** #
#                                   Variable                                   #
# **************************************************************************** #

NAME	= Fixed
OBJ_DIR	= .obj/
CLS_DIR = class/
SRC_DIR	= src/
CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
INC		= -I $(CLS_DIR)
RM		= rm -fr

# **************************************************************************** #
#                                    Colors                                    #
# **************************************************************************** #

BLACK	= \033[0;30m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m
WHITE	= \033[0;37m
DEFAULT	= \033[0;0m

# **************************************************************************** #
#                                    Message                                   #
# **************************************************************************** #

COMP_MSG		= "$(GREEN)Compilation $(NAME) $(DEFAULT)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(DEFAULT)"
CLEAN_MSG		= "$(RED)Cleaning $(NAME) $(DEFAULT)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(DEFAULT)"
FULL_CLEAN_MSG	= "$(PURPLE)Full cleaning $(NAME) $(DEFAULT)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(DEFAULT)"

# **************************************************************************** #
#                                    Sources                                   #
# **************************************************************************** #

CLS_FILES	= Fixed.cpp

ALL_FILES	= $(addprefix $(CLS_DIR), $(CLS_FILES))

SRC_FILES	= main.cpp

ALL_FILES	+= $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_FILES	= $(addprefix $(OBJ_DIR), $(ALL_FILES:.cpp=.o))

DEP_FILES	= $(OBJ_FILES:.o=.d)

# **************************************************************************** #
#                                     Rules                                    #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(INC) $(OBJ_FILES) -o $(NAME)
	echo $(COMP_MSG)

$(OBJ_DIR)%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -MMD -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	echo $(CLEAN_MSG)

fclean: clean
	$(RM) $(NAME)
	echo $(FULL_CLEAN_MSG)

re: fclean all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)$(SRC_DIR) $(OBJ_DIR)$(CLS_DIR)

-include $(DEP_FILES)
