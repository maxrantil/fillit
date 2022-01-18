# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 21:09:30 by mrantil           #+#    #+#              #
#    Updated: 2022/01/18 14:09:26 by mrantil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = *.c # change later
FLAGS = -Wall -Werror -Wextra #-Wpedantic -Wunused -Wconversion -Wunreachable-code -Wtype-limits
LIBFT = -L libft -lft

all: $(NAME)

$(NAME):
#	make -C libft
	gcc $(FLAGS) $(SRCS) -o $(NAME) -I libft $(LIBFT) -g

clean:
#	make -C libft clean
#	rm $(NAME)

fclean: clean
#	make -C libft fclean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
