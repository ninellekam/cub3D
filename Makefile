# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzena <yzena@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/17 22:03:52 by yzena             #+#    #+#              #
#    Updated: 2021/02/18 00:54:59 by yzena            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc
NAME	=	cub3D
CFLAGS	=	-Wall -Wextra -Werror
LIBFT	=	libft
HDRS	=	includes/
SRCS	:=	$(wildcard srcs/*.c)
OBJS	=	$(SRCS:.c=.o)
RM		=	rm -f
MAP		=	maps/valid_1.cub

SRCO = $(SRCS:.c=.o)

LIBFT = $(LIBFTDIR)libft.a

MLX = $(MLXDIR)libmlx.dylib

MLXDIR = ./mlx/

LIBFTDIR = ./libft/

FLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(SRCO) $(LIBFT) $(MLX)
	$(CC) -L./mlx -framework OpenGL -framework AppKit -lmlx -L$(LIBFTDIR) -lft $(SRCO) -o $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)

$(MLX):
	make -C $(MLXDIR)
	cp $(MLXDIR)libmlx.dylib ./

%.o:%.c $(HDRS)
	$(CC) $(FLAGS) -I $(HDRS) -I./mlx -c $< -o $@

clean:
	rm -f $(SRCO)
	make clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	rm -f libmlx.dylib
	rm -f $(MLXDIR)libmlx.dylib
	make fclean -C $(LIBFTDIR)

re: fclean all