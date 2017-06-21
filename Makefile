#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efedorov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/23 14:13:03 by efedorov          #+#    #+#              #
#    Updated: 2017/03/05 15:57:54 by efedorov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

SRC =  main.c \
	create_map.c \
	ft_putendl.c \
	ft_putchar.c \
	ft_putstr.c \
	coords.c \
	coords_mand.c \
	fill_map_circle.c \
	fill_map_julia.c \
	fill_map_mandle.c \
	ft_strcmp.c \
	image.c \
	image_julia.c \
	image_mand.c \
	julia.c \
	key_function_julia.c \
	key_functions.c \
	key_functions_mand.c \
	mandelbrot.c \
    fill_map_cube.c \
    coords_cube.c \
    cube.c \
    newton.c \
    fill_map_newt.c \
    key_func_newt.c \
    coords_newt.c \

OBJ = $(SRC:.c=.o)

HEADER = fractol.h

OFLAGS = -Wall -Wextra -Werror -c -O3

FLAGS = -lmlx -framework OpenGl -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
		gcc $(OFLAGS) $(SRC)
		gcc -o $(NAME) $(OBJ) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
