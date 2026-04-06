# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: michel_32 <michel_32@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 14:08:56 by bkaras-g          #+#    #+#              #
#    Updated: 2026/04/06 17:53:50 by michel_32        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = whoareyou

SRC = 	Base.cpp \
		main.cpp

HEADERS = Base.hpp \
			A.hpp \
			B.hpp \
			C.hpp

RM = rm -f
OBJ := $(patsubst %.cpp, %.o, $(SRC))
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) Makefile
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo  "Mandatory part compilation ok"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -I. -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo  "Clean done"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

dev: all clean

.PHONY: all clean fclean re dev
