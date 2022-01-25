# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 21:09:30 by mrantil           #+#    #+#              #
#    Updated: 2022/01/25 18:48:09 by mrantil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = main.c ft_map_generator.c ft_place_to_map.c ft_shapes_2.c \
	ft_shapes_3.c ft_shapes_draft.c ft_side_total.c ft_verify_pieces_two.c
FLAGS = -Wall -Werror -Wextra
LIBFT = -L libft -lft

all: $(NAME)

$(NAME):
	@echo "Compiling..."
	@make -C libft
	@clang $(FLAGS) $(SRCS) -o $(NAME) -I libft $(LIBFT) -g

clean:
	@echo "Cleaning object files..."
	@make -C libft clean

fclean: clean
	@echo "Cleaning binary..."
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
