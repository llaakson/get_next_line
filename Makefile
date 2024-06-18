# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llaakson <llaakson@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 16:31:06 by llaakson          #+#    #+#              #
#    Updated: 2024/06/16 21:31:21 by llaakson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SOURCES =	get_next_line.c get_next_line_utils.c \

BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c \

HEADF	=	get_next_line.h

OBJECTS = $(SOURCES:%.c=%.o)

CC	=	cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

%.o:	%.c	$(HEADF)
	$(CC)	$(CFLAGS)	-c	$<	-o	$@

$(NAME): $(OBJECTS)
	ar	-rcs	$(NAME) $(OBJECTS)

bonus: .bonus

.bonus: $(OBJECTS) $(OBJECTSBONUS)
	ar	-rcs $(NAME) $(OBJECTS)	$(OBJECTSBONUS)
	@touch .bonus

clean:
	rm -f $(OBJECTS) $(OBJECTSBONUS)

fclean: clean
	rm -f $(NAME)	.bonus

re: fclean all

.PHONY: all clean fclean re bonus

