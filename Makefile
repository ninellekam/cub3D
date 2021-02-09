# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ninakamkia <ninakamkia@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 20:00:38 by serma             #+#    #+#              #
#    Updated: 2021/01/31 13:40:43 by ninakamkia       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard  src/parse_map/*.c src/*.c libft/*.c)
HEADER = includes
CC = gcc
CFLAGS = -g
#LFLAGS = -lmlx
METAL_MLX = -framework OpenGL -framework AppKit
MLXDIR = mlx
NAME = cub3d
all: $(NAME)
$(NAME):
	$(CC) $(CFLAGS) -L$(MLXDIR) -l$(MLXDIR) $(METAL_MLX) -I $(MLXDIR) -I $(HEADER) $(SRCS) -o $(NAME)
fclean:
	rm -fr $(NAME) cub3d.dSYM
re: fclean all
.PHONY: all fclean clean re
