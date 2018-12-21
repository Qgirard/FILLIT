# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hklein <hklein@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 14:34:05 by hklein            #+#    #+#              #
#    Updated: 2018/12/13 16:05:44 by qgirard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FIRST = make -C libft

LAST = make -C libft clean

SUPP = make -C libft fclean

CC = gcc -o

CFLAGS = -Wall -Wextra -Werror

HEADERS = fillit.h

LIBFT = libft/libft.a

SRC = main.c\
	  checklines.c\
	  lists.c\
	  tetricheck.c\
	  resolution.c\
	  print_free.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(FIRST) && $(CC) $(NAME) $(CFLAGS) $(SRC) $(LIBFT)

clean :
	rm -rf $(OBJ)
	$(LAST)

fclean : clean
	$(SUPP)
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
