# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguiller <aguiller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 22:26:44 by aguiller          #+#    #+#              #
#    Updated: 2020/01/27 13:28:43 by aguiller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c

NAME = fdf

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) 
	@cd libft && $(MAKE) all
	@cd minilibx_macos && $(MAKE) all
	@gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -L./libft -lft -L./minilibx_macos -lmlx

%.o:%.c
	@gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	@cd libft && $(MAKE) clean	
	@cd minilibx_macos && $(MAKE) clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@cd libft && $(MAKE) fclean
	@/bin/rm -f $(NAME)

re: fclean  all 

