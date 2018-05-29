#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/27 16:41:37 by kprytkov          #+#    #+#              #
#    Updated: 2018/05/27 16:41:39 by kprytkov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

CC = gcc

FLAG = -Wall -Werror -Wextra

SRC = fractol.c

INCLUDE = ./includes

SRO = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRO)
	make -C ./libft/
	$(CC) $(FLAG) -I$(INCLUDE) $(SRC) -lmlx -framework OpenGL -framework Appkit ./libft/libft.a -o $(NAME)
	# ar rc $(NAME) $(SRO)

%.o: %.c ./includes/fractol.h
	$(CC) $(FLAG) -c -o $@ $<

clean:
	make -C libft/ clean
	rm -f $(SRO)

fclean: clean
	make -C libft/ fclean
	rm -Rf $(NAME)

re: fclean all