# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 16:02:42 by mpascaud          #+#    #+#              #
#    Updated: 2018/03/24 19:07:57 by mpascaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler.a

TAGS =

SRC = mpascaud.filler.c ft_strstr.c get_next_line.c ft_strcpy.c ft_strnew.c \
	  ft_strncat.c ft_strlen.c ft_possible.c ft_heatmap.c ft_board.c ft_piece.c \
	  ft_war.c ft_shapiece.c afficher_variables.c ft_putchar.c ft_putnbr.c \
	  ft_test.c ft_hot.c ft_heatmap_01p2.c ft_heatmap_00p2.c



BIN = $(SRC:.c=.o)


all : $(NAME)

$(NAME) :
	gcc $(TAGS) -c $(SRC)
	ar rc $(NAME) $(BIN)
	ranlib $(NAME)
	gcc -o mpascaud.filler mpascaud.filler.c filler.a

clean:
	rm -fR $(BIN)

fclean: clean
	rm -fR $(NAME)

re: fclean all










