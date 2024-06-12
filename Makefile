# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 16:31:06 by llaakson          #+#    #+#              #
#    Updated: 2024/06/12 18:41:30 by llaakson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SOURCES =	get_next_line.c get_next_line_utils.c \

HEADF	=	get_next_line.h

OBJECTS = $(SOURCES:%.c=%.o)

CC	=	cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o:	%.c	$(HEADF)
	$(CC)	$(CFLAGS)	-c	$<	-o	$@

$(NAME): $(OBJECTS)
	ar	-rcs	$(NAME) $(OBJECTS)
clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
